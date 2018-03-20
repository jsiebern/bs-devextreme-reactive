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
  external makeProps : (~name: string, ~action: 'any_rz0r, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Action";
  let make = (~name: string, ~action: 'any_rj7q => unit, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~name, ~action, ()),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj] external makeProps : (~onChange: 'any_r5lf=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "DragDropProvider";
  let make = (~onChange: option('any_r5lf)=?, children) =>
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
      ~payload: 'any_r3hk,
      ~onStart: 'any_rrb0=?,
      ~onUpdate: 'any_rqeb=?,
      ~onEnd: 'any_rpbz=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "DragSource";
  let make =
      (
        ~payload: 'any_r3hk,
        ~onStart: option('any_rrb0)=?,
        ~onUpdate: option('any_rqeb)=?,
        ~onEnd: option('any_rpbz)=?,
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
      ~onStart: 'any_rro3=?,
      ~onUpdate: 'any_rcya=?,
      ~onEnd: 'any_rru8=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Draggable";
  let make =
      (
        ~onStart: option('any_rro3)=?,
        ~onUpdate: option('any_rcya)=?,
        ~onEnd: option('any_rru8)=?,
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
      ~onEnter: 'any_rf4m=?,
      ~onOver: 'any_rfhd=?,
      ~onLeave: 'any_rqrr=?,
      ~onDrop: 'any_rf3n=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "DropTarget";
  let make =
      (
        ~onEnter: option('any_rf4m)=?,
        ~onOver: option('any_rfhd)=?,
        ~onLeave: option('any_rqrr)=?,
        ~onDrop: option('any_rf3n)=?,
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
    (~name: string, ~value: 'any_rg5l=?, ~computed: 'any_rxtw=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Getter";
  let make =
      (
        ~name: string,
        ~value: option('any_rg5l)=?,
        ~computed: option(Js.t({..}) => 'any_rrt0)=?,
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
    (~name: string=?, ~optional: Js.boolean=?, unit) => typeDependencies =
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
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Boolean.to_js_boolean(v),
          getFromDependencies(madeObj, "optional"),
        ),
      ),
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
    (~position: 'any_r960=?, ~name: string, ~predicate: 'any_rqvj=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-core"]
  external reactClass : ReasonReact.reactClass = "Template";
  let make =
      (
        ~position: option('any_r960)=?,
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
