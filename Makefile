# source = $(wildcard *.cpp)	#auto find the required file
# object = $(patsubset %.cpp, %.o, $(source))

# main : $(object)
# 	g++ -o $@ $(object)
# %.o : %.cpp
# 	g++ -c $<  %.h

result :  result.o MultigridPossion.h MultigridPossion.cpp func.h Restriction.h
	g++ -o result result.o MultigridPossion.h MultigridPossion.cpp Restriction.h -llapacke -lblas
result.o : result.cpp
	g++ -c result.cpp

clean:
	rm *.o *.exe main -fr result

