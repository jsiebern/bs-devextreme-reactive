
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
                
                [@bs.obj] external makeProps : (~name: string,
~action: 'any_r14c, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "Action";
                let make = (
                    ~name: string,
~action: ('any_r580) => unit,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~name=name,
~action=action, ()),
                        children
                    );
            };
        

            module DragDropProvider = {
                
                [@bs.obj] external makeProps : (~onChange: ReactEvent.Form.t => unit=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "DragDropProvider";
                let make = (
                    ~onChange: option(ReactEvent.Form.t => unit)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~onChange=?onChange, ()),
                        children
                    );
            };
        

            module DragSource = {
                
                [@bs.obj] external makeProps : (~payload: 'any_rxhz,
~onStart: 'genericCallback=?,
~onUpdate: 'genericCallback=?,
~onEnd: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "DragSource";
                let make = (
                    ~payload: 'any_rxhz,
~onStart: option('genericCallback)=?,
~onUpdate: option('genericCallback)=?,
~onEnd: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~payload=payload,
~onStart=?onStart,
~onUpdate=?onUpdate,
~onEnd=?onEnd, ()),
                        children
                    );
            };
        

            module Draggable = {
                
                [@bs.obj] external makeProps : (~onStart: 'genericCallback=?,
~onUpdate: 'genericCallback=?,
~onEnd: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "Draggable";
                let make = (
                    ~onStart: option('genericCallback)=?,
~onUpdate: option('genericCallback)=?,
~onEnd: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~onStart=?onStart,
~onUpdate=?onUpdate,
~onEnd=?onEnd, ()),
                        children
                    );
            };
        

            module DropTarget = {
                
                [@bs.obj] external makeProps : (~onEnter: ReactEvent.Synthetic.t => unit=?,
~onOver: 'genericCallback=?,
~onLeave: 'genericCallback=?,
~onDrop: ReactEvent.Mouse.t => unit=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "DropTarget";
                let make = (
                    ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
~onOver: option('genericCallback)=?,
~onLeave: option('genericCallback)=?,
~onDrop: option(ReactEvent.Mouse.t => unit)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~onEnter=?onEnter,
~onOver=?onOver,
~onLeave=?onLeave,
~onDrop=?onDrop, ()),
                        children
                    );
            };
        

            module Getter = {
                
                [@bs.obj] external makeProps : (~name: string,
~value: 'any_rcjx=?,
~computed: 'any_rwq1=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "Getter";
                let make = (
                    ~name: string,
~value: option('any_rcjx)=?,
~computed: option((Js.t({..})) => 'any_rmks)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~name=name,
~value=?value,
~computed=?computed, ()),
                        children
                    );
            };
        

            module PluginHost = {
                
                [@bs.obj] external makeProps : ( unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "PluginHost";
                let make = (
                    
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps( ()),
                        children
                    );
            };
        

            module Plugin = {
                

                    module Dependencies {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                name: string
                            ,
                                [@bs.optional]
                                
                                optional: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    switch (obj -> nameGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "name",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj -> optionalGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "optional",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~name: string=?,
~dependencies: array(Dependencies.t)=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "Plugin";
                let make = (
                    ~name: option(string)=?,
~dependencies: option(array(Dependencies.t))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~name=?name,
~dependencies=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(Dependencies.unwrap(item)), v)), dependencies), ()),
                        children
                    );
            };
        

            module RefHolder = {
                
                [@bs.obj] external makeProps : ( unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "RefHolder";
                let make = (
                    
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps( ()),
                        children
                    );
            };
        

            module Sizer = {
                
                [@bs.obj] external makeProps : (~containerComponent: 'union_rdy7=?,
~style: Js.t({..})=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "Sizer";
                let make = (
                    ~containerComponent: option([ | `String(string) | `Callback('genericCallback)  ])=?,
~style: option(Js.t({..}))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~containerComponent=?Js.Option.map([@bs] (v => unwrapValue(v)), containerComponent),
~style=?style, ()),
                        children
                    );
            };
        

            module TemplateConnector = {
                
                [@bs.obj] external makeProps : ( unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "TemplateConnector";
                let make = (
                    
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps( ()),
                        children
                    );
            };
        

            module TemplatePlaceholder = {
                
                [@bs.obj] external makeProps : (~name: string=?,
~params: Js.t({..})=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "TemplatePlaceholder";
                let make = (
                    ~name: option(string)=?,
~params: option(Js.t({..}))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~name=?name,
~params=?params, ()),
                        children
                    );
            };
        

            module Template = {
                
                [@bs.obj] external makeProps : (~position: 'genericCallback=?,
~name: string,
~predicate: 'any_r9zx=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-core"] external reactClass : ReasonReact.reactClass = "Template";
                let make = (
                    ~position: option('genericCallback)=?,
~name: string,
~predicate: option((Js.t({..})) => bool)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~position=?position,
~name=name,
~predicate=?predicate, ()),
                        children
                    );
            };
        