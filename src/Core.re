external toJsUnsafe : 'a => 'b = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(Js.Boolean.to_js_boolean(b))
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
  external makeProps : (~name: string, ~action: 'any_riz5, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-core/Action"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = (~name: string, ~action: 'any_rswq => unit, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~name, ~action, ()),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj] external makeProps : (~onChange: 'any_rdc8=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-core/DragDropProvider"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = (~onChange: option('any_rdc8)=?, children) =>
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
      ~payload: 'any_rwv7,
      ~onStart: 'any_rc9w=?,
      ~onUpdate: 'any_rsr7=?,
      ~onEnd: 'any_r8kq=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core/DragSource"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~payload: 'any_rwv7,
        ~onStart: option('any_rc9w)=?,
        ~onUpdate: option('any_rsr7)=?,
        ~onEnd: option('any_r8kq)=?,
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
      ~onStart: 'any_refy=?,
      ~onUpdate: 'any_rsap=?,
      ~onEnd: 'any_rtha=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core/Draggable"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~onStart: option('any_refy)=?,
        ~onUpdate: option('any_rsap)=?,
        ~onEnd: option('any_rtha)=?,
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
      ~onEnter: 'any_rty5=?,
      ~onOver: 'any_rj9x=?,
      ~onLeave: 'any_r295=?,
      ~onDrop: 'any_rvhg=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core/DropTarget"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~onEnter: option('any_rty5)=?,
        ~onOver: option('any_rj9x)=?,
        ~onLeave: option('any_r295)=?,
        ~onDrop: option('any_rvhg)=?,
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
    (~name: string, ~value: 'any_r15b=?, ~computed: 'any_rv5n=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core/Getter"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~name: string,
        ~value: option('any_r15b)=?,
        ~computed: option(Js.t({..}) => 'any_ru61)=?,
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
  [@bs.module "@devexpress/dx-react-core/PluginHost"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
};

module Plugin = {
  type typeR4fp;
  [@bs.obj]
  external makeR4fp : (~name: string=?, ~optional: Js.boolean=?, unit) => _ =
    "";
  [@bs.get_index] external getFromR4fp : (typeR4fp, string) => 'a = "";
  let convertR4fp = (madeObj: typeR4fp) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "name", getFromR4fp(madeObj, "name"));
    Js.Dict.set(returnObj, "optional", getFromR4fp(madeObj, "optional"));
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~name: string=?, ~dependencies: array(typeR4fp)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core/Plugin"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~name: option(string)=?,
        ~dependencies: option(array(typeR4fp))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~name?, ~dependencies?, ()),
      children,
    );
};

module TemplateConnector = {
  [@bs.obj] external makeProps : unit => _ = "";
  [@bs.module "@devexpress/dx-react-core/TemplateConnector"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
};

module TemplatePlaceholder = {
  [@bs.obj]
  external makeProps : (~name: string=?, ~params: Js.t({..})=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core/TemplatePlaceholder"]
  external reactClass : ReasonReact.reactClass = "default";
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
    (~position: 'any_rvkt=?, ~name: string, ~predicate: 'any_rm28=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core/Template"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~position: option('any_rvkt)=?,
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
