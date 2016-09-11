# README.md

Hermes is a background process on the Schulich Delta's onboard computer.
It rebroadcasts a data feed from the Central Communication System and also logs the data.

The name is inspired by the Olympian god Hermes who is portrayed as a messenger and scribe of the gods.

## File Structure

You have now successfully cloned the Hermes git repo, next is ensuring that you have the proper file structure.
Originally it should look similar to this:

  - root
    - Hermes

From the directory that this README is currently located in (we assume this is named Hermes), run the command:
    `cd ../ && mv ./Hermes ./src && mkdir Hermes && mv ./src ./Hermes/`  
    (replace Hermes with the name of your cloned directory if it is different)
This will rename the cloned directory to src and move it within a new directory called 'Hermes'.
Your new file structure should look like:

  - root
    - Hermes
      - src

## RabbitMQ Broker

### Getting setup

1) Installing rabbitMQ

In order to send messages, you must have a rabbitMQ server to send the messages to.
This can be installed [here](https://www.rabbitmq.com/) or via the package manager using:

`echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list && sudo apt-get update && sudo apt-get install rabbitmq-server`

2) Installing dependencies for SimpleAmqpClient

First, boost and cmake is required to generate the libraries below, you may install these using your appropriate package manager (such as apt-get on debian).
The following are the commands that could be used on a debian based distro to install these dependencies if you do not already have them.

`sudo apt-get install cmake libboost-dev`

SimpleAmqpClient requires rabbitmq-c, which can be downloaded and compiled from the repository [alanxz/rabbitmq-c](https://github.com/alanxz/rabbitmq-c).
From the src directory of Hermes, start by cloning the repository from github:

`git clone https://github.com/alanxz/rabbitmq-c`

Navigate into this new folder and create a build directory with the following command:

`mkdir rabbitmq-c/build && cd rabbitmq-c/build`

You can now use cmake to generate the library required by SimpleAmqpClient:

`cmake ..`

`cmake --build .`

There should now be a `.a` file in your current directory, as well as multiple `*.so*` files. Use the following commands to make them visible to SimpleAmqpClient:

`sudo cp librabbitmq/*.a /usr/local/lib/`

`sudo cp librabbitmq/*.so* /usr/local/lib/`

Finally navigate back to the src folder:

`cd ../..`

3) Generating SimpleAmqpClient library

SimpleAmqpClient can be downloaded and compiled from [alanxz/SimpleAmqpClient](https://github.com/alanxz/SimpleAmqpClient).
Once again from the src directory, run the following command:

`git clone https://github.com/alanxz/SimpleAmqpClient`

And once again generate a build directory and navigate to it:

`mkdir SimpleAmqpClient/build && cd SimpleAmqpClient/build`

Run the following commands to generate the libraries needed by Hermes:

`cmake -DRabbitmqc_INCLUDE_DIR=../../rabbitmq-c/librabbitmq -DRabbitmqc_LIBRARY=../../rabbitmq-c/build/librabbitmq ..`

`make`


### Start Server

`sudo rabbitmq-server` can be used to start the server on Linux.

### Refresh Server

On linux to refresh the contents of the server perform the following commands:

`rabbitmqctl stop_app`

`rabbitmqctl reset`

`rabbitmqctl start_app`

## Testing

Testing the Schulich Delta Desktop Hermes is done with googletest and googlemock, the gmock and gtest header files need to be in your include path /usr/local/include or /usr/include.

You must compile the library that has the definitions yourself.
Meaning you need a `libgmock.a` archive file in the test directory in order to compile the tests.

To create a `libgmock.a` file in a Linux system follow these instructions in an arbitrary dir.

1. Get the googletest and googlemock source code:
    `git clone https://github.com/google/googletest.git`

2. Go into the cloned directory:
    `cd googletest/`

3. Compile googletest:
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googletest/src/gtest-all.cc`

4. Compile googlemock:
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googlemock/src/gmock-all.cc`

5. Collect both the resulting .o files into an archive file:
    `ar -rv libgmock.a gtest-all.o gmock-all.o`

Congratulations! You now have a `libgmock.a` archive file.
Create a `Hermes/build/.lib` directory using `mkdir -p Hermes/build/.lib` in the root directory and then place the `libmock.a` archive file in the `Hermes/build/.lib/` directory and you should be good to go.
Run `qmake` and then `make` in the `Hermes/src/Tests/` directory to check if you can compile the tests.
Use `ls -a` to show all hidden files.

To get the Settings test to pass, testconfig.ini from `Hermes/src/Tests/` must be copied beside the Tests binary.
Use the following command in the root directory:
    `cp Tests/testconfig.ini ../build/.tests/`

Both gmock and the gtest folders located in `googletest/googlemock/include/` and `googletest/googletest/include/` need to be placed in the `/usr/local/include` system directory.

If you feel there are any issues with the instructions in this README please contact one of the members of the team or open an issue on github against Hermes.
