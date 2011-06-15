CFLAGS:=`pkg-config --cflags eina evas ecore ecore-evas edje`
LDFLAGS:=`pkg-config --libs eina evas ecore ecore-evas edje`

HEADERS:=board.h
SOURCES=zmanim.cpp board.cpp

all: zmanim zmanim.edj

zmanim: ${SOURCES}
	g++ ${SOURCES} ${CFLAGS} ${LDFLAGS} -o zmanim

zmanim.edj: zmanim.edc
	edje_cc zmanim.edc

clean:
	rm -f zmanim zmanim.edj
