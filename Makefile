#
#William Truong wxt160130@utdallss.edu 
#
#

CXX = g++ 
CXXFLAGS = -Wall -g
CPPFLAGS =  -I /scratch/perkins/include
LDFLAGS = -L /scratch/perkins/lib
LDLIBS = -lcdk -lcurses

#
#PROJECT NAME FOR BACKUP FILE 

EXECFILE = cdkexe

SRCS= cdktest2.cc

OBJS = cdktest2.o

all:$(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#*
$(EXECFILE):$(OBJS)
	$(CXX)  -o $@ $(OBJS)  $(LDFLAGS) $(LDLIBS)  
