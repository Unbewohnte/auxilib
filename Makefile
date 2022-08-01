CC=gcc
DEFAULTCFLAGS=-Wall -Werror -O2
SRCDIR=src
LIBNAME=auxlib
BUILDDIR=build
BINDIR=bin
TESTDIR=testing
TESTBIN=test

lib:
	$(CC) $(DEFAULTCFLAGS) -c $(SRCDIR)/*/*.c

	mkdir -p $(BUILDDIR)
	mv *.o $(BUILDDIR)

	mkdir -p $(BINDIR)
	ar rcs $(BINDIR)/$(LIBNAME).a $(BUILDDIR)/*.o


test:
	$(CC) $(DEFAULTCFLAGS) $(TESTDIR)/*.c -o $(TESTDIR)/$(TESTBIN) && \
	 	cd $(TESTDIR) && \
	 	./$(TESTBIN) && \
	 	rm $(TESTBIN)

clear:
	rm -rf $(BUILDDIR) $(BINDIR) $(TESTDIR)/$(TESTBIN)