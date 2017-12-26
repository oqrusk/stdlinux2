FROM gcc:4.9
COPY . /usr/src/cat
WORKDIR /usr/src/cat
RUN gcc -o cat cat.c
CMD ["./cat", "testfile"]
