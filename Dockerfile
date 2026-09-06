ARG EPITECH_IMAGE=epitechcontent/epitest-docker:latest
FROM ${EPITECH_IMAGE}

# Keep the source tree outside the image: the repository is bind-mounted at run time.
WORKDIR /workspace

CMD ["/bin/bash"]
