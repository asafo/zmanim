CFLAGS:=`pkg-config --cflags eina evas ecore ecore-evas edje`
LDFLAGS:=`pkg-config --libs eina evas ecore ecore-evas edje`

HEADERS:=board.h
SOURCES=zmanim.cpp board.cpp controllers/auto_controller.cpp

all: zmanim zmanim.edj interface.edj

zmanim: ${SOURCES}
	g++ -g ${SOURCES} ${CFLAGS} ${LDFLAGS} -o zmanim

%.edj: %.edc
	edje_cc $<

clean:
	rm -f zmanim zmanim.edj timebox.edj
