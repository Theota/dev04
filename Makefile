
geoip: geoip.c config.h
	gcc -Wall -o geoip geoip.c

.PHONY: clean test

clean:
	rm geoip

test:
	./geoip 109.190.106.174 