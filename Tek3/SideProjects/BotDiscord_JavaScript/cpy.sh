#!/bin/bash

sshpass -p XXXXXXXX_SSH_PASSWORD_REDACTED_XXXXXXXX ssh ubuntu@51.91.58.25 "mkdir /home/ubuntu/AntoineTestDesTrucs"
sshpass -p 'XXXXXXXX_SSH_PASSWORD_REDACTED_XXXXXXXX' scp ./* ubuntu@51.91.58.25:/home/ubuntu/AntoineTestDesTrucs/
