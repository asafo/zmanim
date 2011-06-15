CFLAGS:=`pkg-config --cflags eina evas ecore ecore-evas edje`
LDFLAGS:=`pkg-config --libs eina evas ecore ecore-evas edje`

all: zmanim zmanim.edj

zmanim: zmanim.c
	gcc zmanim.c ${CFLAGS} ${LDFLAGS} -o zmanim

zmanim.edj: zmanim.edc
	edje_cc zmanim.edc

clean:
	rm -f zmanim zmanim.edj