librestplus.so: resource.o response.o request.o platform.o service.o
	g++ -fPIC -shared -o librestplus.so resource.o response.o request.o platform.o service.o

resource.o: resource.cpp 
	g++ -c resource.cpp

response.o: response.cpp
	g++ -c response.cpp

request.o: request.cpp
	g++ -c request.cpp

platform.o: platform.cpp
	g++ -c platform.cpp 

service.o: service.cpp 
	g++ -c service.cpp

clean:
	rm librestplus.so *.o 
