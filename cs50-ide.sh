#!/bin/sh

# WORK IN PROGRESS: NOT FOR PRODUCTION

# TO-DO:
# Check what OS is running
# Check if Docker is installed
    # IS NOT INSTALLED: 
        # Alert user that launch failed becuase docker is not installed
        # Install Docker for user
    # IS INSTALLED: 
        # Run/Open Docker for user
        open -a Docker #TODO: ADD TIMEOUT

        # Check if CS50 offline ide is installed
            # IS NOT INSTALLED
                # Install CS50 IDE for user
            # IS INSTALLED
                # Run CS50 IDE
                docker run --privileged -e "OFFLINE_IP=127.0.0.1" -e "OFFLINE_PORT=8080" --name ide50 -d -p 5050:5050 -p 8080-8082:8080-8082 cs50/ide50-offline #TODO: ADD TIMEOUT
                
                docker start ide50 #TODO: ADD TIMEOUT
            # Open Chrome --> localhost:port (to cs50 ide)