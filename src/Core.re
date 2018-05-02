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
  | `Object(_) => assert false
  | `Enum(_) => assert false
  | `EnumArray(_) => assert false;

module Action = {
  [@bs.obj]
  external makeProps : (~name: string, ~action: 'any_rra1, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Action";
  let make = (~name: string, ~action: 'any_rwrb => unit, children) =>
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
      ~payload: 'any_rs9y,
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
        ~payload: 'any_rs9y,
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
    (~name: string, ~value: 'any_rhq7=?, ~computed: 'any_rs2r=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Getter";
  let make =
      (
        ~name: string,
        ~value: option('any_rhq7)=?,
        ~computed: option(Js.t({..}) => 'any_rz3n)=?,
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
  type typeDependencies;
  [@bs.obj]
  external makeDependencies :
    (~name: string=?, ~optional: bool=?, unit) => typeDependencies =
    "";
  [@bs.get_index]
  external getFromDependencies : (typeDependencies, string) => 'a = "";
  let convertDependencies = (madeObj: typeDependencies) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "name",
      toJsUnsafe(getFromDependencies(madeObj, "name")),
    );
    Js.Dict.set(
      returnObj,
      "optional",
      toJsUnsafe(getFromDependencies(madeObj, "optional")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~name: string=?, ~dependencies: array(typeDependencies)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Plugin";
  let make =
      (
        ~name: option(string)=?,
        ~dependencies: option(array(typeDependencies))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~name?,
          ~dependencies=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDependencies(item)),
                  v,
                ),
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
      ~predicate: 'any_re9e=?,
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
