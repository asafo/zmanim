CFLAGS:=`pkg-config --cflags eina evas ecore ecore-evas edje libhdate`
LDFLAGS:=`pkg-config --libs eina evas ecore ecore-evas edje libhdate`

HEADERS:=board.h
SOURCES=zmanim.cpp board.cpp controllers/auto_controller.cpp board_elements/day_times/day_times.cpp

all: zmanim zmanim.edj interface.edj board_elements/day_times/day_times.edj

zmanim: ${SOURCES}
	g++ -g ${SOURCES} ${CFLAGS} ${LDFLAGS} -o zmanim

%.edj: %.edc
	edje_cc $<

clean:
	rm -f zmanim zmanim.edj timebox.edj
