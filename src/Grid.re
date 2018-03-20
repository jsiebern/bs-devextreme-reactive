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

module ColumnChooser = {
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~showColumnChooser: string=?, unit) => _ = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "showColumnChooser",
        getFromMessages(madeObj, "showColumnChooser"),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~overlayComponent: 'any_rxt6=?,
      ~containerComponent: 'any_r2sq=?,
      ~itemComponent: 'any_r16t=?,
      ~toggleButtonComponent: 'any_r1vq=?,
      ~messages: 'any_r22q=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/ColumnChooser"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_rkeq,
               "onHide": unit => unit,
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~containerComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~itemComponent:
           option(
             {
               .
               "item": {
                 .
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r719, string) => 'any_rany,
                 },
                 "hidden": bool,
               },
               "disabled": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~toggleButtonComponent:
           option(
             {
               .
               "onToggle": unit => unit,
               "getMessage": string => string,
               "buttonRef": 'any_r08g => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~overlayComponent?,
          ~containerComponent?,
          ~itemComponent?,
          ~toggleButtonComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module CustomGrouping = {
  type typeRy5h;
  [@bs.obj] external makeRy5h : (~columnName: string, unit) => _ = "";
  [@bs.get_index] external getFromRy5h : (typeRy5h, string) => 'a = "";
  let convertRy5h = (madeObj: typeRy5h) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRy5h(madeObj, "columnName"));
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~getChildGroups: 'any_rqev,
      ~grouping: array(typeRy5h)=?,
      ~expandedGroups: 'invalidArrayType_rzhz=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/CustomGrouping"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~getChildGroups:
           (array('any_r6kq), {. "columnName": string}, array('any_r6qe)) =>
           array(array('any_rtfp)),
        ~grouping: option(array(typeRy5h))=?,
        ~expandedGroups: option('invalidArrayType_rzhz)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~getChildGroups, ~grouping?, ~expandedGroups?, ()),
      children,
    );
};

module CustomPaging = {
  [@bs.obj] external makeProps : (~totalCount: 'number_d=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid/CustomPaging"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (~totalCount: option([ | `Int(int) | `Float(float)])=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~totalCount=?Js.Option.map((. v) => unwrapValue(v), totalCount),
          (),
        ),
      children,
    );
};

module DataTypeProvider = {
  [@bs.obj]
  external makeProps :
    (
      ~_for: array(string),
      ~formatterComponent: 'any_rt7y=?,
      ~editorComponent: 'any_r1j8=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/DataTypeProvider"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~_for: array(string),
        ~formatterComponent:
           option(
             {
               .
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rayt, string) => 'any_rprg,
               },
               "row": 'any_r655,
               "value": 'any_rk9y,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~editorComponent:
           option(
             {
               .
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r285, string) => 'any_rlc3,
               },
               "row": 'any_r4iz,
               "value": 'any_rlx1,
               "onValueChange": 'any_rgtb => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~_for, ~formatterComponent?, ~editorComponent?, ()),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_r542=?, ~columnComponent: 'any_r1ds=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/DragDropProvider"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~containerComponent:
           option(
             {
               .
               "clientOffset": {
                 .
                 "x": [ | `Int(int) | `Float(float)],
                 "y": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnComponent:
           option(
             {
               .
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rpc5, string) => 'any_r1i0,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~containerComponent?, ~columnComponent?, ()),
      children,
    );
};

module EditingState = {
  type typeRtom;
  [@bs.obj]
  external makeRtom :
    (
      ~columnName: string,
      ~editingEnabled: Js.boolean=?,
      ~createRowChange: 'any_rj82=?,
      unit
    ) =>
    _ =
    "";
  [@bs.get_index] external getFromRtom : (typeRtom, string) => 'a = "";
  let convertRtom = (madeObj: typeRtom) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRtom(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "editingEnabled",
      getFromRtom(madeObj, "editingEnabled"),
    );
    Js.Dict.set(
      returnObj,
      "createRowChange",
      getFromRtom(madeObj, "createRowChange"),
    );
    returnObj;
  };
  type typeRhch;
  [@bs.obj]
  external makeRhch :
    (
      ~added: array('any_rri4)=?,
      ~changed: Js.t({..})=?,
      ~deleted: array([ | `Int(int) | `Float(float) | `String(string)])=?,
      unit
    ) =>
    _ =
    "";
  [@bs.get_index] external getFromRhch : (typeRhch, string) => 'a = "";
  let convertRhch = (madeObj: typeRhch) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "added", getFromRhch(madeObj, "added"));
    Js.Dict.set(returnObj, "changed", getFromRhch(madeObj, "changed"));
    Js.Dict.set(returnObj, "deleted", getFromRhch(madeObj, "deleted"));
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~createRowChange: 'any_rkxd=?,
      ~columnEditingEnabled: Js.boolean=?,
      ~columnExtensions: array(typeRtom)=?,
      ~editingRowIds: array(
                        [ | `Int(int) | `Float(float) | `String(string)],
                      )
                        =?,
      ~defaultEditingRowIds: array(
                               [
                                 | `Int(int)
                                 | `Float(float)
                                 | `String(string)
                               ],
                             )
                               =?,
      ~onEditingRowIdsChange: 'any_rmwn=?,
      ~addedRows: array('any_rbe9)=?,
      ~defaultAddedRows: array('any_rgg6)=?,
      ~onAddedRowsChange: 'any_raap=?,
      ~rowChanges: Js.t({..})=?,
      ~defaultRowChanges: Js.t({..})=?,
      ~onRowChangesChange: 'any_r5s8=?,
      ~deletedRowIds: array(
                        [ | `Int(int) | `Float(float) | `String(string)],
                      )
                        =?,
      ~defaultDeletedRowIds: array(
                               [
                                 | `Int(int)
                                 | `Float(float)
                                 | `String(string)
                               ],
                             )
                               =?,
      ~onDeletedRowIdsChange: 'any_r90j=?,
      ~onCommitChanges: 'any_r2gb,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/EditingState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~createRowChange:
           option(
             (
               'any_rii7,
               string,
               [ | `String(string) | `Int(int) | `Float(float)]
             ) =>
             'any_ry58,
           )=?,
        ~columnEditingEnabled: option(bool)=?,
        ~columnExtensions: option(array(typeRtom))=?,
        ~editingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultEditingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onEditingRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        ~addedRows: option(array('any_rbe9))=?,
        ~defaultAddedRows: option(array('any_rgg6))=?,
        ~onAddedRowsChange: option(array('any_ry69) => unit)=?,
        ~rowChanges: option(Js.t({..}))=?,
        ~defaultRowChanges: option(Js.t({..}))=?,
        ~onRowChangesChange: option(Js.t({..}) => unit)=?,
        ~deletedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultDeletedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onDeletedRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        ~onCommitChanges: array(typeRhch) => unit,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~createRowChange?,
          ~columnEditingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnEditingEnabled,
            ),
          ~columnExtensions?,
          ~editingRowIds?,
          ~defaultEditingRowIds?,
          ~onEditingRowIdsChange?,
          ~addedRows?,
          ~defaultAddedRows?,
          ~onAddedRowsChange?,
          ~rowChanges?,
          ~defaultRowChanges?,
          ~onRowChangesChange?,
          ~deletedRowIds?,
          ~defaultDeletedRowIds?,
          ~onDeletedRowIdsChange?,
          ~onCommitChanges,
          (),
        ),
      children,
    );
};

module FilteringState = {
  type typeR5am;
  [@bs.obj]
  external makeR5am : (~columnName: string, ~value: string=?, unit) => _ = "";
  [@bs.get_index] external getFromR5am : (typeR5am, string) => 'a = "";
  let convertR5am = (madeObj: typeR5am) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromR5am(madeObj, "columnName"));
    Js.Dict.set(returnObj, "value", getFromR5am(madeObj, "value"));
    returnObj;
  };
  type typeRk3m;
  [@bs.obj]
  external makeRk3m : (~columnName: string, ~value: string=?, unit) => _ = "";
  [@bs.get_index] external getFromRk3m : (typeRk3m, string) => 'a = "";
  let convertRk3m = (madeObj: typeRk3m) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRk3m(madeObj, "columnName"));
    Js.Dict.set(returnObj, "value", getFromRk3m(madeObj, "value"));
    returnObj;
  };
  type typeR9n7;
  [@bs.obj]
  external makeR9n7 : (~columnName: string, ~value: string=?, unit) => _ = "";
  [@bs.get_index] external getFromR9n7 : (typeR9n7, string) => 'a = "";
  let convertR9n7 = (madeObj: typeR9n7) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromR9n7(madeObj, "columnName"));
    Js.Dict.set(returnObj, "value", getFromR9n7(madeObj, "value"));
    returnObj;
  };
  type typeRpl4;
  [@bs.obj]
  external makeRpl4 :
    (~columnName: string, ~filteringEnabled: Js.boolean, unit) => _ =
    "";
  [@bs.get_index] external getFromRpl4 : (typeRpl4, string) => 'a = "";
  let convertRpl4 = (madeObj: typeRpl4) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRpl4(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "filteringEnabled",
      getFromRpl4(madeObj, "filteringEnabled"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~filters: array(typeR5am)=?,
      ~defaultFilters: array(typeRk3m)=?,
      ~onFiltersChange: 'any_r3l3=?,
      ~columnExtensions: array(typeRpl4)=?,
      ~columnFilteringEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/FilteringState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~filters: option(array(typeR5am))=?,
        ~defaultFilters: option(array(typeRk3m))=?,
        ~onFiltersChange: option(array(typeR9n7) => unit)=?,
        ~columnExtensions: option(array(typeRpl4))=?,
        ~columnFilteringEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~filters?,
          ~defaultFilters?,
          ~onFiltersChange?,
          ~columnExtensions?,
          ~columnFilteringEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnFilteringEnabled,
            ),
          (),
        ),
      children,
    );
};

module Grid = {
  type typeRklm;
  [@bs.obj]
  external makeRklm :
    (~name: string, ~title: string=?, ~getCellValue: 'any_rsd1=?, unit) => _ =
    "";
  [@bs.get_index] external getFromRklm : (typeRklm, string) => 'a = "";
  let convertRklm = (madeObj: typeRklm) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "name", getFromRklm(madeObj, "name"));
    Js.Dict.set(returnObj, "title", getFromRklm(madeObj, "title"));
    Js.Dict.set(
      returnObj,
      "getCellValue",
      getFromRklm(madeObj, "getCellValue"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~rows: array('any_rnyz)=?,
      ~getRowId: 'any_rew5=?,
      ~getCellValue: 'any_rpwi=?,
      ~columns: array(typeRklm)=?,
      ~rootComponent: 'any_rcrn=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/Grid"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~rows: option(array('any_rnyz))=?,
        ~getRowId:
           option(
             'any_r08p => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_r2y3, string) => 'any_rsq0)=?,
        ~columns: option(array(typeRklm))=?,
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~rows?,
          ~getRowId?,
          ~getCellValue?,
          ~columns?,
          ~rootComponent?,
          (),
        ),
      children,
    );
};

module GroupPanelLayout = {
  type typeRnpy;
  [@bs.obj]
  external makeRnpy : (~column: Js.t({..})=?, ~draft: Js.boolean=?, unit) => _ =
    "";
  [@bs.get_index] external getFromRnpy : (typeRnpy, string) => 'a = "";
  let convertRnpy = (madeObj: typeRnpy) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "column", getFromRnpy(madeObj, "column"));
    Js.Dict.set(returnObj, "draft", getFromRnpy(madeObj, "draft"));
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~items: array(typeRnpy),
      ~onGroup: 'any_rl77=?,
      ~itemComponent: 'any_rgfv,
      ~containerComponent: 'any_rgt3,
      ~emptyMessageComponent: 'any_rai1,
      ~draggingEnabled: Js.boolean=?,
      ~isColumnGroupingEnabled: 'any_ru6b=?,
      ~onGroupDraft: 'any_rf6w=?,
      ~onGroupDraftCancel: 'any_rjn0=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/GroupPanelLayout"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~items: array(typeRnpy),
        ~onGroup: option('any_rl77)=?,
        ~itemComponent: 'any_rgfv,
        ~containerComponent: 'any_rgt3,
        ~emptyMessageComponent: 'any_rai1,
        ~draggingEnabled: option(bool)=?,
        ~isColumnGroupingEnabled: option('any_ru6b)=?,
        ~onGroupDraft: option('any_rf6w)=?,
        ~onGroupDraftCancel: option('any_rjn0)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~items,
          ~onGroup?,
          ~itemComponent,
          ~containerComponent,
          ~emptyMessageComponent,
          ~draggingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              draggingEnabled,
            ),
          ~isColumnGroupingEnabled?,
          ~onGroupDraft?,
          ~onGroupDraftCancel?,
          (),
        ),
      children,
    );
};

module GroupingPanel = {
  [@bs.deriving jsConverter]
  type sortingDirection_r1s5 = [
    | [@bs.as "asc"] `Asc
    | [@bs.as "desc"] `Desc
  ];
  [@bs.deriving jsConverter]
  type rlql_ryj7 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeMessages;
  [@bs.obj] external makeMessages : (~groupByColumn: string=?, unit) => _ = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "groupByColumn",
        getFromMessages(madeObj, "groupByColumn"),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: Js.boolean=?,
      ~showGroupingControls: Js.boolean=?,
      ~layoutComponent: 'any_rmzn=?,
      ~containerComponent: 'any_r4du=?,
      ~itemComponent: 'any_rghk=?,
      ~emptyMessageComponent: 'any_rfry=?,
      ~messages: 'any_rtgy=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/GroupingPanel"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~layoutComponent: option('any_rmzn)=?,
        ~containerComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~itemComponent:
           option(
             {
               .
               "item": {
                 .
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r5kx, string) => 'any_r7nw,
                 },
                 "draft": string,
               },
               "showGroupingControls": bool,
               "showSortingControls": bool,
               "groupingEnabled": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection_r1s5,
               "onSort":
                 {. "direction": [ | `Any('any_r01a) | `Enum(rlql_ryj7)]} =>
                 unit,
               "onGroup": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~emptyMessageComponent:
           option(
             {. "getMessage": string => string} => ReasonReact.reactElement,
           )=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~showSortingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSortingControls,
            ),
          ~showGroupingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showGroupingControls,
            ),
          ~layoutComponent?,
          ~containerComponent?,
          ~itemComponent?,
          ~emptyMessageComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module GroupingState = {
  type typeRsvv;
  [@bs.obj] external makeRsvv : (~columnName: string, unit) => _ = "";
  [@bs.get_index] external getFromRsvv : (typeRsvv, string) => 'a = "";
  let convertRsvv = (madeObj: typeRsvv) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRsvv(madeObj, "columnName"));
    returnObj;
  };
  type typeRwit;
  [@bs.obj] external makeRwit : (~columnName: string, unit) => _ = "";
  [@bs.get_index] external getFromRwit : (typeRwit, string) => 'a = "";
  let convertRwit = (madeObj: typeRwit) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRwit(madeObj, "columnName"));
    returnObj;
  };
  type typeR67e;
  [@bs.obj] external makeR67e : (~columnName: string, unit) => _ = "";
  [@bs.get_index] external getFromR67e : (typeR67e, string) => 'a = "";
  let convertR67e = (madeObj: typeR67e) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromR67e(madeObj, "columnName"));
    returnObj;
  };
  type typeRo0z;
  [@bs.obj]
  external makeRo0z :
    (~columnName: string, ~groupingEnabled: Js.boolean, unit) => _ =
    "";
  [@bs.get_index] external getFromRo0z : (typeRo0z, string) => 'a = "";
  let convertRo0z = (madeObj: typeRo0z) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRo0z(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "groupingEnabled",
      getFromRo0z(madeObj, "groupingEnabled"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~grouping: array(typeRsvv)=?,
      ~defaultGrouping: array(typeRwit)=?,
      ~onGroupingChange: 'any_rqqx=?,
      ~expandedGroups: 'invalidArrayType_r3wm=?,
      ~defaultExpandedGroups: 'invalidArrayType_r50j=?,
      ~onExpandedGroupsChange: 'any_rq0z=?,
      ~columnExtensions: array(typeRo0z)=?,
      ~columnGroupingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/GroupingState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~grouping: option(array(typeRsvv))=?,
        ~defaultGrouping: option(array(typeRwit))=?,
        ~onGroupingChange: option(array(typeR67e) => unit)=?,
        ~expandedGroups: option('invalidArrayType_r3wm)=?,
        ~defaultExpandedGroups: option('invalidArrayType_r50j)=?,
        ~onExpandedGroupsChange: option('invalidArrayType_ryz1 => unit)=?,
        ~columnExtensions: option(array(typeRo0z))=?,
        ~columnGroupingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~grouping?,
          ~defaultGrouping?,
          ~onGroupingChange?,
          ~expandedGroups?,
          ~defaultExpandedGroups?,
          ~onExpandedGroupsChange?,
          ~columnExtensions?,
          ~columnGroupingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnGroupingEnabled,
            ),
          (),
        ),
      children,
    );
};

module IntegratedFiltering = {
  type typeRrfq;
  [@bs.obj]
  external makeRrfq : (~columnName: string, ~predicate: 'any_rwz1=?, unit) => _ =
    "";
  [@bs.get_index] external getFromRrfq : (typeRrfq, string) => 'a = "";
  let convertRrfq = (madeObj: typeRrfq) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRrfq(madeObj, "columnName"));
    Js.Dict.set(returnObj, "predicate", getFromRrfq(madeObj, "predicate"));
    returnObj;
  };
  [@bs.obj]
  external makeProps : (~columnExtensions: array(typeRrfq)=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid/IntegratedFiltering"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = (~columnExtensions: option(array(typeRrfq))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~columnExtensions?, ()),
      children,
    );
};

module IntegratedGrouping = {
  type typeCriteriaReturn;
  [@bs.obj]
  external makeCriteriaReturn :
    (~key: 'union_r7si, ~value: 'any_rau4=?, unit) => _ =
    "";
  [@bs.get_index]
  external getFromCriteriaReturn : (typeCriteriaReturn, string) => 'a = "";
  let convertCriteriaReturn = (madeObj: typeCriteriaReturn) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "key", getFromCriteriaReturn(madeObj, "key"));
    Js.Dict.set(returnObj, "value", getFromCriteriaReturn(madeObj, "value"));
    returnObj;
  };
  type typeRnj5;
  [@bs.obj]
  external makeRnj5 : (~columnName: string, ~criteria: 'any_r6h6=?, unit) => _ =
    "";
  [@bs.get_index] external getFromRnj5 : (typeRnj5, string) => 'a = "";
  let convertRnj5 = (madeObj: typeRnj5) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRnj5(madeObj, "columnName"));
    Js.Dict.set(returnObj, "criteria", getFromRnj5(madeObj, "criteria"));
    returnObj;
  };
  [@bs.obj]
  external makeProps : (~columnExtensions: array(typeRnj5)=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid/IntegratedGrouping"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = (~columnExtensions: option(array(typeRnj5))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~columnExtensions?, ()),
      children,
    );
};

module IntegratedPaging = {
  [@bs.module "@devexpress/dx-react-grid/IntegratedPaging"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module IntegratedSelection = {
  [@bs.module "@devexpress/dx-react-grid/IntegratedSelection"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module IntegratedSorting = {
  type typeRdbu;
  [@bs.obj]
  external makeRdbu : (~columnName: string, ~compare: 'any_rpny=?, unit) => _ =
    "";
  [@bs.get_index] external getFromRdbu : (typeRdbu, string) => 'a = "";
  let convertRdbu = (madeObj: typeRdbu) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRdbu(madeObj, "columnName"));
    Js.Dict.set(returnObj, "compare", getFromRdbu(madeObj, "compare"));
    returnObj;
  };
  [@bs.obj]
  external makeProps : (~columnExtensions: array(typeRdbu)=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid/IntegratedSorting"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = (~columnExtensions: option(array(typeRdbu))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~columnExtensions?, ()),
      children,
    );
};

module PagingPanel = {
  type typeMessages;
  [@bs.obj]
  external makeMessages :
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_rbcq=?, unit) => _ =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(returnObj, "showAll", getFromMessages(madeObj, "showAll"));
      Js.Dict.set(
        returnObj,
        "rowsPerPage",
        getFromMessages(madeObj, "rowsPerPage"),
      );
      Js.Dict.set(returnObj, "info", getFromMessages(madeObj, "info"));
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~pageSizes: 'arrayOf_r86c=?,
      ~containerComponent: 'any_rfyr=?,
      ~messages: 'any_rqzg=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/PagingPanel"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~pageSizes:
           option([ | `IntArray(array(int)) | `FloatArray(array(float))])=?,
        ~containerComponent:
           option(
             {
               .
               "totalPages": [ | `Int(int) | `Float(float)],
               "currentPage": [ | `Int(int) | `Float(float)],
               "onCurrentPageChange": [ | `Int(int) | `Float(float)] => unit,
               "pageSize": [ | `Int(int) | `Float(float)],
               "onPageSizeChange": [ | `Int(int) | `Float(float)] => unit,
               "pageSizes": [
                 | `IntArray(array(int))
                 | `FloatArray(array(float))
               ],
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~pageSizes?,
          ~containerComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module PagingState = {
  [@bs.obj]
  external makeProps :
    (
      ~pageSize: 'number_4=?,
      ~defaultPageSize: 'number_9=?,
      ~onPageSizeChange: 'any_rn3e=?,
      ~currentPage: 'number_8=?,
      ~defaultCurrentPage: 'number_g=?,
      ~onCurrentPageChange: 'any_rd03=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/PagingState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~pageSize: option([ | `Int(int) | `Float(float)])=?,
        ~defaultPageSize: option([ | `Int(int) | `Float(float)])=?,
        ~onPageSizeChange: option([ | `Int(int) | `Float(float)] => unit)=?,
        ~currentPage: option([ | `Int(int) | `Float(float)])=?,
        ~defaultCurrentPage: option([ | `Int(int) | `Float(float)])=?,
        ~onCurrentPageChange: option([ | `Int(int) | `Float(float)] => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~pageSize=?Js.Option.map((. v) => unwrapValue(v), pageSize),
          ~defaultPageSize=?
            Js.Option.map((. v) => unwrapValue(v), defaultPageSize),
          ~onPageSizeChange?,
          ~currentPage=?Js.Option.map((. v) => unwrapValue(v), currentPage),
          ~defaultCurrentPage=?
            Js.Option.map((. v) => unwrapValue(v), defaultCurrentPage),
          ~onCurrentPageChange?,
          (),
        ),
      children,
    );
};

module RowDetailState = {
  [@bs.obj]
  external makeProps :
    (
      ~expandedRowIds: array(
                         [ | `Int(int) | `Float(float) | `String(string)],
                       )
                         =?,
      ~defaultExpandedRowIds: array(
                                [
                                  | `Int(int)
                                  | `Float(float)
                                  | `String(string)
                                ],
                              )
                                =?,
      ~onExpandedRowIdsChange: 'any_rug2=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/RowDetailState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~expandedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultExpandedRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onExpandedRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~expandedRowIds?,
          ~defaultExpandedRowIds?,
          ~onExpandedRowIdsChange?,
          (),
        ),
      children,
    );
};

module SearchPanel = {
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~searchPlaceholder: string=?, unit) => _ = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "searchPlaceholder",
        getFromMessages(madeObj, "searchPlaceholder"),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (~inputComponent: 'any_rqq1=?, ~messages: 'any_ri9s=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/SearchPanel"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~inputComponent:
           option(
             {
               .
               "value": string,
               "onValueChange": unit => unit,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~inputComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module SearchState = {
  [@bs.obj]
  external makeProps :
    (
      ~value: string=?,
      ~defaultValue: string=?,
      ~onValueChange: 'any_rhox=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/SearchState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~value: option(string)=?,
        ~defaultValue: option(string)=?,
        ~onValueChange: option(string => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~value?, ~defaultValue?, ~onValueChange?, ()),
      children,
    );
};

module SelectionState = {
  [@bs.obj]
  external makeProps :
    (
      ~selection: array([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~defaultSelection: array(
                           [ | `Int(int) | `Float(float) | `String(string)],
                         )
                           =?,
      ~onSelectionChange: 'any_r6pn=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/SelectionState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~selection:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultSelection:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onSelectionChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(~selection?, ~defaultSelection?, ~onSelectionChange?, ()),
      children,
    );
};

module SortingState = {
  [@bs.deriving jsConverter]
  type direction_r6y3 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeRft5;
  [@bs.obj]
  external makeRft5 :
    (~columnName: string, ~direction: direction_r6y3, unit) => _ =
    "";
  [@bs.get_index] external getFromRft5 : (typeRft5, string) => 'a = "";
  let convertRft5 = (madeObj: typeRft5) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRft5(madeObj, "columnName"));
    Js.Dict.set(returnObj, "direction", getFromRft5(madeObj, "direction"));
    returnObj;
  };
  [@bs.deriving jsConverter]
  type direction_ruw9 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeRfh1;
  [@bs.obj]
  external makeRfh1 :
    (~columnName: string, ~direction: direction_ruw9, unit) => _ =
    "";
  [@bs.get_index] external getFromRfh1 : (typeRfh1, string) => 'a = "";
  let convertRfh1 = (madeObj: typeRfh1) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRfh1(madeObj, "columnName"));
    Js.Dict.set(returnObj, "direction", getFromRfh1(madeObj, "direction"));
    returnObj;
  };
  [@bs.deriving jsConverter]
  type direction_rhmo = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeR4rs;
  [@bs.obj]
  external makeR4rs :
    (~columnName: string, ~direction: direction_rhmo, unit) => _ =
    "";
  [@bs.get_index] external getFromR4rs : (typeR4rs, string) => 'a = "";
  let convertR4rs = (madeObj: typeR4rs) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromR4rs(madeObj, "columnName"));
    Js.Dict.set(returnObj, "direction", getFromR4rs(madeObj, "direction"));
    returnObj;
  };
  type typeRut7;
  [@bs.obj]
  external makeRut7 :
    (~columnName: string, ~sortingEnabled: Js.boolean, unit) => _ =
    "";
  [@bs.get_index] external getFromRut7 : (typeRut7, string) => 'a = "";
  let convertRut7 = (madeObj: typeRut7) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRut7(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "sortingEnabled",
      getFromRut7(madeObj, "sortingEnabled"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~sorting: array(typeRft5)=?,
      ~defaultSorting: array(typeRfh1)=?,
      ~onSortingChange: 'any_rwnf=?,
      ~columnExtensions: array(typeRut7)=?,
      ~columnSortingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/SortingState"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~sorting: option(array(typeRft5))=?,
        ~defaultSorting: option(array(typeRfh1))=?,
        ~onSortingChange: option(array(typeR4rs) => unit)=?,
        ~columnExtensions: option(array(typeRut7))=?,
        ~columnSortingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~sorting?,
          ~defaultSorting?,
          ~onSortingChange?,
          ~columnExtensions?,
          ~columnSortingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnSortingEnabled,
            ),
          (),
        ),
      children,
    );
};

module StaticTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~headerRows: array('any_rkrx)=?,
      ~rows: array('any_r1oi),
      ~columns: array('any_ry67),
      ~minWidth: 'number_v,
      ~containerComponent: 'any_r3u0,
      ~tableComponent: 'any_rcrc,
      ~headComponent: 'any_rfg8=?,
      ~bodyComponent: 'any_rd50,
      ~rowComponent: 'any_ro12,
      ~cellComponent: 'any_r914,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/StaticTableLayout"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~headerRows: option(array('any_rkrx))=?,
        ~rows: array('any_r1oi),
        ~columns: array('any_ry67),
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~containerComponent: 'any_r3u0,
        ~tableComponent: 'any_rcrc,
        ~headComponent: option('any_rfg8)=?,
        ~bodyComponent: 'any_rd50,
        ~rowComponent: 'any_ro12,
        ~cellComponent: 'any_r914,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~headerRows?,
          ~rows,
          ~columns,
          ~minWidth=unwrapValue(minWidth),
          ~containerComponent,
          ~tableComponent,
          ~headComponent?,
          ~bodyComponent,
          ~rowComponent,
          ~cellComponent,
          (),
        ),
      children,
    );
};

module TableColumnReordering = {
  [@bs.obj]
  external makeProps :
    (
      ~order: array(string)=?,
      ~defaultOrder: array(string)=?,
      ~onOrderChange: 'any_r3y7=?,
      ~tableContainerComponent: 'any_r72a=?,
      ~rowComponent: 'any_rbdf=?,
      ~cellComponent: 'any_rdmj=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableColumnReordering"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~order: option(array(string))=?,
        ~defaultOrder: option(array(string))=?,
        ~onOrderChange: option(array(string) => unit)=?,
        ~tableContainerComponent: option('any_r72a)=?,
        ~rowComponent: option('any_rbdf)=?,
        ~cellComponent: option('any_rdmj)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~order?,
          ~defaultOrder?,
          ~onOrderChange?,
          ~tableContainerComponent?,
          ~rowComponent?,
          ~cellComponent?,
          (),
        ),
      children,
    );
};

module TableColumnResizing = {
  type typeRq55;
  [@bs.obj]
  external makeRq55 : (~columnName: string, ~width: 'number_z, unit) => _ = "";
  [@bs.get_index] external getFromRq55 : (typeRq55, string) => 'a = "";
  let convertRq55 = (madeObj: typeRq55) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRq55(madeObj, "columnName"));
    Js.Dict.set(returnObj, "width", getFromRq55(madeObj, "width"));
    returnObj;
  };
  type typeRmsi;
  [@bs.obj]
  external makeRmsi : (~columnName: string, ~width: 'number_w, unit) => _ = "";
  [@bs.get_index] external getFromRmsi : (typeRmsi, string) => 'a = "";
  let convertRmsi = (madeObj: typeRmsi) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRmsi(madeObj, "columnName"));
    Js.Dict.set(returnObj, "width", getFromRmsi(madeObj, "width"));
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(typeRq55)=?,
      ~columnWidths: array(typeRmsi)=?,
      ~onColumnWidthsChange: 'any_rl2w=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableColumnResizing"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~defaultColumnWidths: option(array(typeRq55))=?,
        ~columnWidths: option(array(typeRmsi))=?,
        ~onColumnWidthsChange: option(Js.t({..}) => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~defaultColumnWidths?,
          ~columnWidths?,
          ~onColumnWidthsChange?,
          (),
        ),
      children,
    );
};

module TableColumnVisibility = {
  type typeMessages;
  [@bs.obj] external makeMessages : (~noColumns: string=?, unit) => _ = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "noColumns",
        getFromMessages(madeObj, "noColumns"),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  type typeR4lz;
  [@bs.obj]
  external makeR4lz :
    (~columnName: string, ~togglingEnabled: Js.boolean, unit) => _ =
    "";
  [@bs.get_index] external getFromR4lz : (typeR4lz, string) => 'a = "";
  let convertR4lz = (madeObj: typeR4lz) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromR4lz(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "togglingEnabled",
      getFromR4lz(madeObj, "togglingEnabled"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_reml=?,
      ~onHiddenColumnNamesChange: 'any_r13o=?,
      ~messages: 'any_rc4c=?,
      ~columnExtensions: array(typeR4lz)=?,
      ~columnTogglingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableColumnVisibility"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~hiddenColumnNames: option(array(string))=?,
        ~defaultHiddenColumnNames: option(array(string))=?,
        ~emptyMessageComponent:
           option(
             {. "getMessage": string => string} => ReasonReact.reactElement,
           )=?,
        ~onHiddenColumnNamesChange: option(array(string) => unit)=?,
        ~messages: option(typeMessages)=?,
        ~columnExtensions: option(array(typeR4lz))=?,
        ~columnTogglingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~hiddenColumnNames?,
          ~defaultHiddenColumnNames?,
          ~emptyMessageComponent?,
          ~onHiddenColumnNamesChange?,
          ~messages=?convertMessages(messages),
          ~columnExtensions?,
          ~columnTogglingEnabled=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              columnTogglingEnabled,
            ),
          (),
        ),
      children,
    );
};

module TableEditColumn = {
  [@bs.deriving jsConverter]
  type align_rg9m = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rmkz = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type id_rhi1 = [
    | [@bs.as "add"] `Add
    | [@bs.as "edit"] `Edit
    | [@bs.as "delete"] `Delete
    | [@bs.as "commit"] `Commit
    | [@bs.as "cancel"] `Cancel
  ];
  type typeMessages;
  [@bs.obj]
  external makeMessages :
    (
      ~addCommand: string=?,
      ~editCommand: string=?,
      ~deleteCommand: string=?,
      ~commitCommand: string=?,
      ~cancelCommand: string=?,
      unit
    ) =>
    _ =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "addCommand",
        getFromMessages(madeObj, "addCommand"),
      );
      Js.Dict.set(
        returnObj,
        "editCommand",
        getFromMessages(madeObj, "editCommand"),
      );
      Js.Dict.set(
        returnObj,
        "deleteCommand",
        getFromMessages(madeObj, "deleteCommand"),
      );
      Js.Dict.set(
        returnObj,
        "commitCommand",
        getFromMessages(madeObj, "commitCommand"),
      );
      Js.Dict.set(
        returnObj,
        "cancelCommand",
        getFromMessages(madeObj, "cancelCommand"),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rdew=?,
      ~headerCellComponent: 'any_rb6m=?,
      ~commandComponent: 'any_rcp3=?,
      ~showAddCommand: Js.boolean=?,
      ~showEditCommand: Js.boolean=?,
      ~showDeleteCommand: Js.boolean=?,
      ~width: 'union_rzrd=?,
      ~messages: 'any_rtar=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableEditColumn"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r8jg,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r5ma, string) => 'any_rjbz,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rg9m,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rbhr,
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~headerCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rtl4,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r62b, string) => 'any_ryxl,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rmkz,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~commandComponent:
           option(
             {
               .
               "id": id_rhi1,
               "text": string,
               "onExecute": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~showAddCommand: option(bool)=?,
        ~showEditCommand: option(bool)=?,
        ~showDeleteCommand: option(bool)=?,
        ~width: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~cellComponent?,
          ~headerCellComponent?,
          ~commandComponent?,
          ~showAddCommand=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showAddCommand,
            ),
          ~showEditCommand=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showEditCommand,
            ),
          ~showDeleteCommand=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showDeleteCommand,
            ),
          ~width=?Js.Option.map((. v) => unwrapValue(v), width),
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module TableEditRow = {
  [@bs.deriving jsConverter]
  type align_rhyq = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_f=?,
      ~cellComponent: 'any_racw=?,
      ~rowComponent: 'any_r35r=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableEditRow"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rqvf,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rjnr, string) => 'any_r60t,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rhyq,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rdz7,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rd3t, string) => 'any_rbpl,
               },
               "value": 'any_r4bm,
               "editingEnabled": bool,
               "onValueChange": 'any_r196 => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_raeu,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_r1fx,
             } =>
             ReasonReact.reactElement,
           )=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~rowHeight=?Js.Option.map((. v) => unwrapValue(v), rowHeight),
          ~cellComponent?,
          ~rowComponent?,
          (),
        ),
      children,
    );
};

module TableFilterRow = {
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~filterPlaceholder: string=?, unit) => _ = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "filterPlaceholder",
        getFromMessages(madeObj, "filterPlaceholder"),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.deriving jsConverter]
  type align_rxsz = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_g=?,
      ~messages: 'any_rp4m=?,
      ~cellComponent: 'any_rg9d=?,
      ~rowComponent: 'any_r67r=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableFilterRow"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~messages: option(typeMessages)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rum2,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rga2, string) => 'any_rzx7,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rxsz,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "filter": {
                 .
                 "columnName": string,
                 "value": string,
               },
               "onFilter":
                 {
                   .
                   "columnName": string,
                   "value": string,
                 } =>
                 unit,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rn3n, string) => 'any_r463,
               },
               "filteringEnabled": bool,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~rowHeight=?Js.Option.map((. v) => unwrapValue(v), rowHeight),
          ~messages=?convertMessages(messages),
          ~cellComponent?,
          ~rowComponent?,
          (),
        ),
      children,
    );
};

module TableGroupRow = {
  [@bs.deriving jsConverter]
  type align_rlen = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rwnp = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  type typeRbic;
  [@bs.obj]
  external makeRbic :
    (~columnName: string, ~showWhenGrouped: Js.boolean=?, unit) => _ =
    "";
  [@bs.get_index] external getFromRbic : (typeRbic, string) => 'a = "";
  let convertRbic = (madeObj: typeRbic) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRbic(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "showWhenGrouped",
      getFromRbic(madeObj, "showWhenGrouped"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rlx5=?,
      ~rowComponent: 'any_r3y1=?,
      ~indentCellComponent: 'any_rky0=?,
      ~indentColumnWidth: 'number_0=?,
      ~showColumnsWhenGrouped: Js.boolean=?,
      ~columnExtensions: array(typeRbic)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableGroupRow"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rbqr,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rgza, string) => 'any_rrqc,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rlen,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rf8m,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rz1o, string) => 'any_rv3a,
               },
               "expanded": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rq2p,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r15e,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rzxl,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rsfs, string) => 'any_rvks,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rwnp,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rict,
               },
               "column": 'any_r956,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~showColumnsWhenGrouped: option(bool)=?,
        ~columnExtensions: option(array(typeRbic))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~cellComponent?,
          ~rowComponent?,
          ~indentCellComponent?,
          ~indentColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), indentColumnWidth),
          ~showColumnsWhenGrouped=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showColumnsWhenGrouped,
            ),
          ~columnExtensions?,
          (),
        ),
      children,
    );
};

module TableHeaderRow = {
  [@bs.deriving jsConverter]
  type align_rzwq = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type sortingDirection_rmo9 = [
    | [@bs.as "asc"] `Asc
    | [@bs.as "desc"] `Desc
  ];
  [@bs.deriving jsConverter]
  type r57a_r2y4 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeMessages;
  [@bs.obj] external makeMessages : (~sortingHint: string=?, unit) => _ = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "sortingHint",
        getFromMessages(madeObj, "sortingHint"),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: Js.boolean=?,
      ~showGroupingControls: Js.boolean=?,
      ~cellComponent: 'any_rsrx=?,
      ~rowComponent: 'any_r4r3=?,
      ~messages: 'any_r0c5=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableHeaderRow"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rjpr,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r9oe, string) => 'any_r3tq,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rzwq,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_ro3a, string) => 'any_rw65,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection_rmo9,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r6dk) | `Enum(r57a_r2y4)],
                   "keepOther": bool,
                 } =>
                 unit,
               "showGroupingControls": bool,
               "groupingEnabled": bool,
               "onGroup": unit => unit,
               "resizingEnabled": bool,
               "onWidthChange": 'any_ra3o => unit,
               "onWidthDraft": 'any_rxoy => unit,
               "onWidthDraftCancel": unit => unit,
               "draggingEnabled": bool,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~showSortingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSortingControls,
            ),
          ~showGroupingControls=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showGroupingControls,
            ),
          ~cellComponent?,
          ~rowComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};

module TableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~columns: array('any_rwz5),
      ~minColumnWidth: 'number_6,
      ~layoutComponent: 'any_rywp,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableLayout"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~columns: array('any_rwz5),
        ~minColumnWidth: [ | `Int(int) | `Float(float)],
        ~layoutComponent: 'any_rywp,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columns,
          ~minColumnWidth=unwrapValue(minColumnWidth),
          ~layoutComponent,
          (),
        ),
      children,
    );
};

module TableRowDetail = {
  [@bs.deriving jsConverter]
  type align_rb9r = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_r372 = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~contentComponent: 'any_rgt8=?,
      ~toggleCellComponent: 'any_r1dn=?,
      ~cellComponent: 'any_r9kb=?,
      ~rowComponent: 'any_re79=?,
      ~toggleColumnWidth: 'number_6=?,
      ~rowHeight: 'number_7=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableRowDetail"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rma7} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rsyc,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rhdi, string) => 'any_rwl7,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rb9r,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rg8e,
               "expanded": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rq4n,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rhvh, string) => 'any_rv1m,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_r372,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r0gi,
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rw2e,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_r004,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~toggleColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~contentComponent?,
          ~toggleCellComponent?,
          ~cellComponent?,
          ~rowComponent?,
          ~toggleColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), toggleColumnWidth),
          ~rowHeight=?Js.Option.map((. v) => unwrapValue(v), rowHeight),
          (),
        ),
      children,
    );
};

module TableSelection = {
  [@bs.deriving jsConverter]
  type align_rqm0 = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_r29f = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~headerCellComponent: 'any_roxt=?,
      ~cellComponent: 'any_rqdv=?,
      ~rowComponent: 'any_rv59=?,
      ~highlightRow: Js.boolean=?,
      ~selectByRowClick: Js.boolean=?,
      ~showSelectAll: Js.boolean=?,
      ~showSelectionColumn: Js.boolean=?,
      ~selectionColumnWidth: 'number_6=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/TableSelection"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~headerCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rude,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r5d5, string) => 'any_rx2u,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rqm0,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "disabled": bool,
               "allSelected": bool,
               "someSelected": bool,
               "onToggle": bool => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rc6e,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_r9bz, string) => 'any_rwwz,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_r29f,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rke0,
               "selected": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option('any_rv59)=?,
        ~highlightRow: option(bool)=?,
        ~selectByRowClick: option(bool)=?,
        ~showSelectAll: option(bool)=?,
        ~showSelectionColumn: option(bool)=?,
        ~selectionColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~headerCellComponent?,
          ~cellComponent?,
          ~rowComponent?,
          ~highlightRow=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              highlightRow,
            ),
          ~selectByRowClick=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              selectByRowClick,
            ),
          ~showSelectAll=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSelectAll,
            ),
          ~showSelectionColumn=?
            Js.Option.map(
              (. v) => Js.Boolean.to_js_boolean(v),
              showSelectionColumn,
            ),
          ~selectionColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), selectionColumnWidth),
          (),
        ),
      children,
    );
};

module Table = {
  [@bs.deriving jsConverter]
  type align_rdm5 = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_r9qu = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rvv4 = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_reiz = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  type typeR8lf;
  [@bs.obj]
  external makeR8lf :
    (~columnName: string, ~width: 'number_2=?, ~align: align_reiz=?, unit) => _ =
    "";
  [@bs.get_index] external getFromR8lf : (typeR8lf, string) => 'a = "";
  let convertR8lf = (madeObj: typeR8lf) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromR8lf(madeObj, "columnName"));
    Js.Dict.set(returnObj, "width", getFromR8lf(madeObj, "width"));
    Js.Dict.set(returnObj, "align", getFromR8lf(madeObj, "align"));
    returnObj;
  };
  type typeMessages;
  [@bs.obj] external makeMessages : (~noData: string=?, unit) => _ = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(returnObj, "noData", getFromMessages(madeObj, "noData"));
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~layoutComponent: 'any_rpxp=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_rq16=?,
      ~rowComponent: 'any_rmxb=?,
      ~noDataCellComponent: 'any_rhas=?,
      ~noDataRowComponent: 'any_r7n9=?,
      ~stubCellComponent: 'any_r95c=?,
      ~stubHeaderCellComponent: 'any_rrv5=?,
      ~columnExtensions: array(typeR8lf)=?,
      ~messages: 'any_r5o6=?,
      ~fixedHeaderComponent: 'any_rfc4=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/Table"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~layoutComponent: option('any_rpxp)=?,
        ~tableComponent: option(ReasonReact.reactElement)=?,
        ~headComponent: option(ReasonReact.reactElement)=?,
        ~bodyComponent: option(ReasonReact.reactElement)=?,
        ~containerComponent: option(ReasonReact.reactElement)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rx6p,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rqki, string) => 'any_r1ir,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rdm5,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rual,
               "row": 'any_rl1k,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rrfl, string) => 'any_rnpf,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rko3,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_r9k6,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~noDataCellComponent:
           option(
             {. "getMessage": string => string} => ReasonReact.reactElement,
           )=?,
        ~noDataRowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rsnw,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
             } =>
             ReasonReact.reactElement,
           )=?,
        ~stubCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r4ah,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_rvwj, string) => 'any_r6lv,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_r9qu,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~stubHeaderCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rmo2,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "tableColumn": {
                 .
                 "key": string,
                 "type": string,
                 "column": {
                   .
                   "name": string,
                   "title": string,
                   "getCellValue": ('any_ri6e, string) => 'any_ryky,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rvv4,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(typeR8lf))=?,
        ~messages: option(typeMessages)=?,
        ~fixedHeaderComponent: option('any_rfc4)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~layoutComponent?,
          ~tableComponent?,
          ~headComponent?,
          ~bodyComponent?,
          ~containerComponent?,
          ~cellComponent?,
          ~rowComponent?,
          ~noDataCellComponent?,
          ~noDataRowComponent?,
          ~stubCellComponent?,
          ~stubHeaderCellComponent?,
          ~columnExtensions?,
          ~messages=?convertMessages(messages),
          ~fixedHeaderComponent?,
          (),
        ),
      children,
    );
};

module Toolbar = {
  [@bs.obj]
  external makeProps :
    (
      ~rootComponent: 'any_rkoq=?,
      ~flexibleSpaceComponent: 'any_ras5=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/Toolbar"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~flexibleSpaceComponent: option('any_ras5)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~rootComponent?, ~flexibleSpaceComponent?, ()),
      children,
    );
};

module VirtualTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~minWidth: 'number_c,
      ~height: 'number_w,
      ~headerRows: array('any_rph0)=?,
      ~rows: array('any_rjar),
      ~columns: array('any_rpdr),
      ~cellComponent: 'any_r2mk,
      ~rowComponent: 'any_rgz4,
      ~bodyComponent: 'any_r8ek,
      ~headComponent: 'any_rv2l=?,
      ~tableComponent: 'any_rtwk,
      ~headTableComponent: 'any_rndg=?,
      ~containerComponent: 'any_ri3a,
      ~estimatedRowHeight: 'number_7,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid/VirtualTableLayout"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~height: [ | `Int(int) | `Float(float)],
        ~headerRows: option(array('any_rph0))=?,
        ~rows: array('any_rjar),
        ~columns: array('any_rpdr),
        ~cellComponent: 'any_r2mk,
        ~rowComponent: 'any_rgz4,
        ~bodyComponent: 'any_r8ek,
        ~headComponent: option('any_rv2l)=?,
        ~tableComponent: 'any_rtwk,
        ~headTableComponent: option('any_rndg)=?,
        ~containerComponent: 'any_ri3a,
        ~estimatedRowHeight: [ | `Int(int) | `Float(float)],
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~minWidth=unwrapValue(minWidth),
          ~height=unwrapValue(height),
          ~headerRows?,
          ~rows,
          ~columns,
          ~cellComponent,
          ~rowComponent,
          ~bodyComponent,
          ~headComponent?,
          ~tableComponent,
          ~headTableComponent?,
          ~containerComponent,
          ~estimatedRowHeight=unwrapValue(estimatedRowHeight),
          (),
        ),
      children,
    );
};
