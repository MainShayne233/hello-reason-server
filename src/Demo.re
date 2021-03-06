open Serbet.Endpoint;
open Async;

module HelloEndpoint = {
  [@decco.decode]
  type params = {name: string};

  let endpoint =
    Serbet.endpoint({
      verb: GET,
      path: "/hello/:name",
      handler: req => {
        let%Async params = req.requireParams(params_decode);
        OkString("Hello there, " ++ params.name)->async;
      },
    });
};

let app = Serbet.application([HelloEndpoint.endpoint]);
