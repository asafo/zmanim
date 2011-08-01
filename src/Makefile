CFLAGS:=`pkg-config --cflags eina evas ecore ecore-evas edje libhdate fribidi`
LDFLAGS:=`pkg-config --libs eina evas ecore ecore-evas edje libhdate fribidi`

HEADERS:=board.h
SOURCES:=zmanim.cpp board.cpp modules/date.cpp  modules/daytimes.cpp
EDJE_FILES:=basic.edj

all: zmanim ${EDJE_FILES}

zmanim: ${SOURCES}
	g++ -g ${SOURCES} ${CFLAGS} ${LDFLAGS} -o zmanim

%.edj: %.edc
	edje_cc $<

clean:
	rm -f zmanim ${EDJE_FILES}
