
uname_s := $(shell uname -s)

define make_pdf
	if [ $(uname_s) = "Darwin" ]; then \
		groff -pet -T ps -ms $(1) | pstopdf -i -o $(1).pdf; \
	else \
		groff -pet -T ps -ms $(1) | ps2pdf - $(1).pdf; \
	fi
endef

all: grades syllabus 

.PHONY: clean

grades: grading-criteria.ms
	tbl grading-criteria.ms > grading-criteria.tbl

syllabus: syllabus.ms
	$(call make_pdf,$@.ms)

clean:
	rm -f grading-criteria.tbl
	rm -f *.pdf

