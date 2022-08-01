CC=gcc
DEFAULTCFLAGS=-Wall -Werror -O2
SRCDIR=src
LIBNAME=auxlib.a
BUILDDIR=build
BINDIR=bin
TESTDIR=testing
TESTBIN=test

lib:
	$(CC) $(DEFAULTCFLAGS) -c $(SRCDIR)/*/*.c

	mkdir -p $(BUILDDIR)
	mv *.o $(BUILDDIR)

	mkdir -p $(BINDIR)
	ar rcs $(BINDIR)/$(LIBNAME) $(BUILDDIR)/*.o


test:
	$(CC) $(DEFAULTCFLAGS) $(TESTDIR)/$(TESTBIN).c $(SRCDIR)/*/*.c -o $(TESTDIR)/$(TESTBIN) && \
	 	cd $(TESTDIR) && \
	 	./$(TESTBIN) && \
	 	rm $(TESTBIN)

test_static: lib
	$(CC) $(DEFAULTCFLAGS) $(TESTDIR)/$(TESTBIN).c $(BINDIR)/$(LIBNAME) -static -o $(TESTDIR)/$(TESTBIN) && \
	cd $(TESTDIR) && \
	./$(TESTBIN) && \
	rm $(TESTBIN)

clear:
	rm -rf $(BUILDDIR) $(BINDIR) $(TESTDIR)/$(TESTBIN)