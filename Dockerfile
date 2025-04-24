# Use latest GCC image
FROM gcc:latest

# Set working directory
WORKDIR /app

# Copy C++ source file
COPY Demo.cpp .

# Compile with C++11 standard
RUN g++ -std=c++11 -o demo Demo.cpp

# Run the app interactively
CMD ["./demo"]
