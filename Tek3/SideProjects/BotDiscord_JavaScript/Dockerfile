FROM node:lts-alpine

ADD package.json package-lock.json /
RUN npm ci --production
ADD run.js /
RUN chmod +x /run.js

ENTRYPOINT ["node", "/run.js"]