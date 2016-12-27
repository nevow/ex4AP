# weichsn1 305108706
# darsham1 203393210

a.out: main.o BFS.o Map.o Node.o Point.o TripEndListener.o MainFlow.o SystemOperations.o Cab.o LuxuryCab.o Driver.o Passenger.o Satisfaction.o TaxiCenter.o TripInfo.o ProperInput.o
	g++ -std=c++0x main.o BFS.o Map.o Node.o Point.o TripEndListener.o MainFlow.o SystemOperations.o Cab.o LuxuryCab.o Driver.o Passenger.o Satisfaction.o TaxiCenter.o TripInfo.o ProperInput.o

main.o: src/main.cpp
	g++ -std=c++0x -c src/main.cpp

BFS.o: src/managment/BFS.cpp src/managment/BFS.h src/coordinates/Grid.h src/coordinates/CoordinatedItem.h
	g++ -std=c++0x -c src/managment/BFS.cpp

Map.o: src/coordinates/Map.cpp src/coordinates/Map.h
	g++ -std=c++0x -c src/coordinates/Map.cpp

Node.o: src/coordinates/Node.cpp src/coordinates/Node.h
	g++ -std=c++0x -c src/coordinates/Node.cpp

Point.o: src/coordinates/Point.cpp src/coordinates/Point.h
	g++ -std=c++0x -c src/coordinates/Point.cpp

TripEndListener.o: src/listeners/TripEndListener.cpp src/listeners/TripEndListener.h
	g++ -std=c++0x -c src/listeners/TripEndListener.cpp

MainFlow.o: src/managment/MainFlow.cpp src/managment/MainFlow.h src/enum/CarManufactureFactory.h src/enum/ColorFactory.h src/enum/MartialStatuesFactory.h
	g++ -std=c++0x -c src/managment/MainFlow.cpp

SystemOperations.o: src/managment/SystemOperations.cpp src/managment/SystemOperations.h
	g++ -std=c++0x -c src/managment/SystemOperations.cpp

Cab.o: src/taxi/Cab.cpp src/taxi/Cab.h
	g++ -std=c++0x -c src/taxi/Cab.cpp

LuxuryCab.o: src/taxi/LuxuryCab.cpp src/taxi/LuxuryCab.h
	g++ -std=c++0x -c src/taxi/LuxuryCab.cpp

Driver.o: src/tripOperations/Driver.cpp src/tripOperations/Driver.h src/enum/MartialStatues.h
	g++ -std=c++0x -c src/tripOperations/Driver.cpp

Passenger.o: src/tripOperations/Passenger.cpp src/tripOperations/Passenger.h
	g++ -std=c++0x -c src/tripOperations/Passenger.cpp

Satisfaction.o: src/tripOperations/Satisfaction.cpp src/tripOperations/Satisfaction.h
	g++ -std=c++0x -c src/tripOperations/Satisfaction.cpp

TaxiCenter.o: src/tripOperations/TaxiCenter.cpp src/tripOperations/TaxiCenter.h src/taxi/Taxi.h src/enum/Color.h src/enum/CarManufacture.h src/listeners/EventListener.h
	g++ -std=c++0x -c src/tripOperations/TaxiCenter.cpp

TripInfo.o: src/tripOperations/TripInfo.cpp src/tripOperations/TripInfo.h
	g++ -std=c++0x -c src/tripOperations/TripInfo.cpp

ProperInput.o:src/managment/ProperInput.cpp src/managment/ProperInput.h
	g++ -std=c++0x -c src/managment/ProperInput.cpp

clean:
	rm -f *.o a.out

