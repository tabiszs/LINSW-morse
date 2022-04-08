#include <gpiod.h>
#include <error.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

struct gpiod_chip *chip;
struct gpiod_line_bulk lines;
struct gpiod_line_bulk events;

int
main(int argc, char *argv[])
{
  unsigned int offsets[1];

  int values[1];
  int err;
  struct timespec timeout;

  chip = gpiod_chip_open("/dev/gpiochip0");
  if(!chip)
  {
    perror("gpiod_chip_open");
    goto cleanup;
  }

  // use pin 4 as input
  offsets[0] = 4;
  values[0] = -1;

  err = gpiod_chip_get_lines(chip, offsets, 1, &lines);
  if(err)
  {
    perror("gpiod_chip_get_lines");
    goto cleanup;
  }

  err = gpiod_line_request_bulk_rising_edge_events(&lines, "rising edge example");
  if(err)
  {
    perror("gpiod_line_request_bulk_rising_edge_events");
    goto cleanup;
  }

  // Timeout of 60 seconds, pass in NULL to wait forever
  timeout.tv_sec = 60;
  timeout.tv_nsec = 0;

  printf("waiting for rising edge event\n");

  err = gpiod_line_event_wait_bulk(&lines, &timeout, &events);
  if(err == -1)
  {
    perror("gpiod_line_event_wait_bulk");
    goto cleanup;
  }
  else if(err == 0)
  {
    fprintf(stderr, "wait timed out\n");
    goto cleanup;
  }

  err = gpiod_line_get_value_bulk(&events, values);
  if(err)gpiod_line_event_wait_bulk
  {
    perror("gpiod_line_get_value_bulk");
    goto cleanup;
  }

  for(int i=0; i<gpiod_line_bulk_num_lines(&events); i++)
  {
    struct gpiod_line* line;
    line = gpiod_line_bulk_get_line(&events, i);
    if(!line)
    {
      fprintf(stderr, "unable to get line %d\n", i);
      continue;
    }
    printf("line %s(%dn", gpiod_line_name(line), gpiod_line_offset(line));
  }

cleanup:
  gpiod_line_release_bulk(&lines);
  gpiod_chip_close(chip);

  return EXIT_SUCCESS;
}