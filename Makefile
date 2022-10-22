CC=gcc
DEFAULTCCFLAGS=-Wall -Werror -O2
SRCDIR=src
LIBNAME=auxlib.a
BUILDDIR=build
BINDIR=bin
TESTDIR=testing
TESTBIN=test

lib:
	$(CC) $(DEFAULTCCFLAGS) -c $(SRCDIR)/*/*.c

	mkdir -p $(BUILDDIR)
	mv *.o $(BUILDDIR)

	mkdir -p $(BINDIR)
	ar rcs $(BINDIR)/$(LIBNAME) $(BUILDDIR)/*.o

test:
	$(CC) $(DEFAULTCCFLAGS) $(TESTDIR)/$(TESTBIN).c $(SRCDIR)/*/*.c -o $(TESTDIR)/$(TESTBIN) -lm && \
	 	cd $(TESTDIR) && \
	 	./$(TESTBIN) && \
	 	rm $(TESTBIN)

test_static: lib
	$(CC) $(DEFAULTCCFLAGS) $(TESTDIR)/$(TESTBIN).c $(BINDIR)/$(LIBNAME) -static -lm -o $(TESTDIR)/$(TESTBIN) && \
	cd $(TESTDIR) && \
	./$(TESTBIN) && \
	rm $(TESTBIN)

clean:
	rm -rf $(BUILDDIR) $(BINDIR) $(TESTDIR)/$(TESTBIN)