#
#William Truong wxt160130@utdallss.edu 
#
#

CXX = g++ 
CXXFLAGS = 
CPPFLAGS = -Wall -g -I/people/cs/s/wxt160130/include
LDFLAGS = -L/people/cs/w/wxt160130/lib
LDLIBS = -lcdk -lcurses

#
#PROJECT NAME FOR BACKUP FILE 

EXECFILE = cdkexe

OBJS = cdk1.o

all:$(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#*
$(EXECFILE):$(OBJS)
	$(CXX) -o $@ $(OBJS)$(LDFLAGS)$(LDLIBS) 
