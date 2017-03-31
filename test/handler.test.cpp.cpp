//
// Created by jsanchez on 31/03/17.
//


#include <catch.hpp>
#include <fakeit.hpp>
using namespace fakeit;


typedef std::string Request;

struct RequestProcessor {
  // if not virtual: "DynamicProxy requires a polymorphic type"
  virtual ~RequestProcessor() = default;
  virtual void processRequest(Request) {}
};

struct Handler {
  Handler(RequestProcessor * p) { processor = p;}
  void handle(Request request) { processor->processRequest(request);}
  RequestProcessor * processor;
};

TEST_CASE("Handler processes incoming requests", "[mock]") {
  Mock<RequestProcessor> processor;
  Fake(Method(processor,processRequest));
  Handler handler(&(processor.get()));
  Request sampleRequest("requestContent");
  handler.handle(sampleRequest);
  Verify(Method(processor,processRequest).Using(sampleRequest)).Exactly(1_Times);
}