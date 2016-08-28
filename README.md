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
This can be installed [here](https://www.rabbitmq.com/)

2) Installing dependencies for SimpleAmqpClient

SimpleAmqpClient requires rabbitmq-c, which can be downloaded and compiled from the repository [alanxz/rabbitmq-c](https://github.com/alanxz/rabbitmq-c)
This repository contains instructions on how to generate a library in the README

3) Generating SimpleAmqpClient library

SimpleAmqpClient can be downloaded and compiled from [alanxz/SimpleAmqpClient](https://github.com/alanxz/SimpleAmqpClient)
This repository once again contains instructions on how to generate the library in the README.

4) Adding libraries to path

Both of these libraries must be added to your PATH environment variable, in order for the project to be able to see and use it.
On linux this can also be done by adding them to `/usr/local/lib`

5) Header files

The header files in these libraries must also be visible.
On linux this can be accomplished by moving AMQP/ and SimpleAmqpClient/ containing the header files to /usr/include or /usr/local/include

### Start Server

`sudo rabbitmq-server` can be used to start the server on Linux

### Refresh Server

On linux to refresh the contents of the server perform the following commands

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

2. Go into the cloned directory
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
Use the following command in the root directory
    `cp Tests/testconfig.ini ../build/.tests/`

Both gmock and the gtest folders located in `googletest/googlemock/include/` and `googletest/googletest/include/` need to be placed in the `/usr/local/include` system directory.
