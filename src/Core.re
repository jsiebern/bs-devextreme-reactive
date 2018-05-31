external toJsUnsafe : 'a => 'b = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(b)
  | `Float(f) => toJsUnsafe(f)
  | `Int(i) => toJsUnsafe(i)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `ObjectArray(oa) => toJsUnsafe(oa)
  | `StringArray(sa) => toJsUnsafe(sa)
  | `IntArray(ia) => toJsUnsafe(ia)
  | `FloatArray(fa) => toJsUnsafe(fa)
  | `ObjectGeneric(og) => toJsUnsafe(og)
  | `Array(ag) => toJsUnsafe(ag)
  | `Any(an) => toJsUnsafe(an)
  | `Object(_) => assert(false)
  | `Enum(_) => assert(false)
  | `EnumArray(_) => assert(false);

module Action = {
  [@bs.obj]
  external makeProps : (~name: string, ~action: 'any_r7s9, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Action";
  let make = (~name: string, ~action: 'any_rpk6 => unit, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~name, ~action, ()),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj]
  external makeProps : (~onChange: ReactEventRe.Form.t => unit=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "DragDropProvider";
  let make = (~onChange: option(ReactEventRe.Form.t => unit)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~onChange?, ()),
      children,
    );
};

module DragSource = {
  [@bs.obj]
  external makeProps :
    (
      ~payload: 'any_r4jl,
      ~onStart: 'genericCallback=?,
      ~onUpdate: 'genericCallback=?,
      ~onEnd: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "DragSource";
  let make =
      (
        ~payload: 'any_r4jl,
        ~onStart: option('genericCallback)=?,
        ~onUpdate: option('genericCallback)=?,
        ~onEnd: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~payload, ~onStart?, ~onUpdate?, ~onEnd?, ()),
      children,
    );
};

module Draggable = {
  [@bs.obj]
  external makeProps :
    (
      ~onStart: 'genericCallback=?,
      ~onUpdate: 'genericCallback=?,
      ~onEnd: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Draggable";
  let make =
      (
        ~onStart: option('genericCallback)=?,
        ~onUpdate: option('genericCallback)=?,
        ~onEnd: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~onStart?, ~onUpdate?, ~onEnd?, ()),
      children,
    );
};

module DropTarget = {
  [@bs.obj]
  external makeProps :
    (
      ~onEnter: ReactEventRe.Synthetic.t => unit=?,
      ~onOver: 'genericCallback=?,
      ~onLeave: 'genericCallback=?,
      ~onDrop: ReactEventRe.Mouse.t => unit=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "DropTarget";
  let make =
      (
        ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
        ~onOver: option('genericCallback)=?,
        ~onLeave: option('genericCallback)=?,
        ~onDrop: option(ReactEventRe.Mouse.t => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~onEnter?, ~onOver?, ~onLeave?, ~onDrop?, ()),
      children,
    );
};

module Getter = {
  [@bs.obj]
  external makeProps :
    (~name: string, ~value: 'any_rjxp=?, ~computed: 'any_rtay=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Getter";
  let make =
      (
        ~name: string,
        ~value: option('any_rjxp)=?,
        ~computed: option(Js.t({..}) => 'any_rv8j)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~name, ~value?, ~computed?, ()),
      children,
    );
};

module PluginHost = {
  [@bs.obj] external makeProps : unit => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "PluginHost";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
};

module Plugin = {
  [@bs.deriving abstract]
  type dependencies = {
    name: string,
    optional: bool,
  };

  [@bs.obj]
  external makeProps :
    (~name: string=?, ~dependencies: array(dependencies)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Plugin";
  let make =
      (
        ~name: option(string)=?,
        ~dependencies: option(array(dependencies))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~name?,
          ~dependencies=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              dependencies,
            ),
          (),
        ),
      children,
    );
};

module RefHolder = {
  [@bs.obj] external makeProps : unit => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "RefHolder";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
};

module Sizer = {
  [@bs.obj] external makeProps : unit => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Sizer";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
};

module TemplateConnector = {
  [@bs.obj] external makeProps : unit => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "TemplateConnector";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
};

module TemplatePlaceholder = {
  [@bs.obj]
  external makeProps : (~name: string=?, ~params: Js.t({..})=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "TemplatePlaceholder";
  let make =
      (~name: option(string)=?, ~params: option(Js.t({..}))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~name?, ~params?, ()),
      children,
    );
};

module Template = {
  [@bs.obj]
  external makeProps :
    (
      ~position: 'genericCallback=?,
      ~name: string,
      ~predicate: 'any_rnyq=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Template";
  let make =
      (
        ~position: option('genericCallback)=?,
        ~name: string,
        ~predicate: option(Js.t({..}) => bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~position?, ~name, ~predicate?, ()),
      children,
    );
};
