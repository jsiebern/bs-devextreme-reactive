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
      ~overlayComponent: 'any_rw95=?,
      ~containerComponent: 'any_r081=?,
      ~itemComponent: 'any_r1i4=?,
      ~toggleButtonComponent: 'any_rne0=?,
      ~messages: 'any_r5uw=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/ColumnChooser"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_rysl,
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
                   "getCellValue": ('any_rtht, string) => 'any_rhkd,
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
               "buttonRef": 'any_rzf5 => unit,
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

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_rwmq=?, ~columnComponent: 'any_rrlh=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/DragDropProvider"]
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
                 "getCellValue": ('any_r7ug, string) => 'any_r8h7,
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

module Grid = {
  type typeR6nd;
  [@bs.obj]
  external makeR6nd :
    (~name: string, ~title: string=?, ~getCellValue: 'any_rbln=?, unit) => _ =
    "";
  [@bs.get_index] external getFromR6nd : (typeR6nd, string) => 'a = "";
  let convertR6nd = (madeObj: typeR6nd) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "name", getFromR6nd(madeObj, "name"));
    Js.Dict.set(returnObj, "title", getFromR6nd(madeObj, "title"));
    Js.Dict.set(
      returnObj,
      "getCellValue",
      getFromR6nd(madeObj, "getCellValue"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~rows: array('any_rgdw)=?,
      ~getRowId: 'any_rw65=?,
      ~getCellValue: 'any_r9oq=?,
      ~columns: array(typeR6nd)=?,
      ~rootComponent: 'any_r2e5=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/Grid"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~rows: option(array('any_rgdw))=?,
        ~getRowId:
           option(
             'any_r4b7 => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_r6nv, string) => 'any_r8z3)=?,
        ~columns: option(array(typeR6nd))=?,
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

module GroupingPanel = {
  [@bs.deriving jsConverter]
  type sortingDirection_ragw = [
    | [@bs.as "asc"] `Asc
    | [@bs.as "desc"] `Desc
  ];
  [@bs.deriving jsConverter]
  type rbk5_rd1f = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
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
      ~layoutComponent: 'any_rxf5=?,
      ~containerComponent: 'any_rquj=?,
      ~itemComponent: 'any_r6km=?,
      ~emptyMessageComponent: 'any_rr0i=?,
      ~messages: 'any_rpp2=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/GroupingPanel"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~layoutComponent: option('any_rxf5)=?,
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
                   "getCellValue": ('any_rud5, string) => 'any_rdtr,
                 },
                 "draft": string,
               },
               "showGroupingControls": bool,
               "showSortingControls": bool,
               "groupingEnabled": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection_ragw,
               "onSort":
                 {. "direction": [ | `Any('any_r39c) | `Enum(rbk5_rd1f)]} =>
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

module PagingPanel = {
  type typeMessages;
  [@bs.obj]
  external makeMessages :
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_rcpo=?, unit) => _ =
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
      ~pageSizes: 'arrayOf_r9fk=?,
      ~containerComponent: 'any_rjij=?,
      ~messages: 'any_rk12=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/PagingPanel"]
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
    (~inputComponent: 'any_rgno=?, ~messages: 'any_r94f=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/SearchPanel"]
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

module TableColumnReordering = {
  [@bs.obj]
  external makeProps :
    (
      ~order: array(string)=?,
      ~defaultOrder: array(string)=?,
      ~onOrderChange: 'any_ruv7=?,
      ~tableContainerComponent: 'any_rw3u=?,
      ~rowComponent: 'any_rab7=?,
      ~cellComponent: 'any_r0nr=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableColumnReordering"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~order: option(array(string))=?,
        ~defaultOrder: option(array(string))=?,
        ~onOrderChange: option(array(string) => unit)=?,
        ~tableContainerComponent: option('any_rw3u)=?,
        ~rowComponent: option('any_rab7)=?,
        ~cellComponent: option('any_r0nr)=?,
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
  type typeRzux;
  [@bs.obj]
  external makeRzux : (~columnName: string, ~width: 'number_3, unit) => _ = "";
  [@bs.get_index] external getFromRzux : (typeRzux, string) => 'a = "";
  let convertRzux = (madeObj: typeRzux) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRzux(madeObj, "columnName"));
    Js.Dict.set(returnObj, "width", getFromRzux(madeObj, "width"));
    returnObj;
  };
  type typeRc51;
  [@bs.obj]
  external makeRc51 : (~columnName: string, ~width: 'number_a, unit) => _ = "";
  [@bs.get_index] external getFromRc51 : (typeRc51, string) => 'a = "";
  let convertRc51 = (madeObj: typeRc51) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRc51(madeObj, "columnName"));
    Js.Dict.set(returnObj, "width", getFromRc51(madeObj, "width"));
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(typeRzux)=?,
      ~columnWidths: array(typeRc51)=?,
      ~onColumnWidthsChange: 'any_rhe6=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableColumnResizing"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~defaultColumnWidths: option(array(typeRzux))=?,
        ~columnWidths: option(array(typeRc51))=?,
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
  type typeReyf;
  [@bs.obj]
  external makeReyf :
    (~columnName: string, ~togglingEnabled: Js.boolean, unit) => _ =
    "";
  [@bs.get_index] external getFromReyf : (typeReyf, string) => 'a = "";
  let convertReyf = (madeObj: typeReyf) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromReyf(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "togglingEnabled",
      getFromReyf(madeObj, "togglingEnabled"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_rj8h=?,
      ~onHiddenColumnNamesChange: 'any_rfaj=?,
      ~messages: 'any_r2ws=?,
      ~columnExtensions: array(typeReyf)=?,
      ~columnTogglingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableColumnVisibility"]
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
        ~columnExtensions: option(array(typeReyf))=?,
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
  type align_rezq = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rfms = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type id_rtg1 = [
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
      ~cellComponent: 'any_rapu=?,
      ~headerCellComponent: 'any_r59v=?,
      ~commandComponent: 'any_ra09=?,
      ~showAddCommand: Js.boolean=?,
      ~showEditCommand: Js.boolean=?,
      ~showDeleteCommand: Js.boolean=?,
      ~width: 'union_rqb7=?,
      ~messages: 'any_rab8=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableEditColumn"]
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
                 "row": 'any_rjtz,
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
                   "getCellValue": ('any_r3xt, string) => 'any_rx57,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rezq,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rxbq,
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
                 "row": 'any_ru84,
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
                   "getCellValue": ('any_r3ij, string) => 'any_rfa6,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rfms,
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
               "id": id_rtg1,
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
  type align_rshh = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_s=?,
      ~cellComponent: 'any_robv=?,
      ~rowComponent: 'any_race=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableEditRow"]
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
                 "row": 'any_rjjj,
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
                   "getCellValue": ('any_r5ja, string) => 'any_rg95,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rshh,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_re0s,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rdm5, string) => 'any_rk6w,
               },
               "value": 'any_rfcu,
               "editingEnabled": bool,
               "onValueChange": 'any_rqoi => unit,
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
                 "row": 'any_rkuy,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rak7,
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
  type align_roqe = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_p=?,
      ~messages: 'any_r1in=?,
      ~cellComponent: 'any_r17s=?,
      ~rowComponent: 'any_ruq4=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableFilterRow"]
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
                 "row": 'any_ridr,
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
                   "getCellValue": ('any_r4ts, string) => 'any_rn5s,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_roqe,
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
                 "getCellValue": ('any_r7qg, string) => 'any_rff4,
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
  type align_rrn8 = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_r6sc = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  type typeR4jx;
  [@bs.obj]
  external makeR4jx :
    (~columnName: string, ~showWhenGrouped: Js.boolean=?, unit) => _ =
    "";
  [@bs.get_index] external getFromR4jx : (typeR4jx, string) => 'a = "";
  let convertR4jx = (madeObj: typeR4jx) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromR4jx(madeObj, "columnName"));
    Js.Dict.set(
      returnObj,
      "showWhenGrouped",
      getFromR4jx(madeObj, "showWhenGrouped"),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rni2=?,
      ~rowComponent: 'any_r377=?,
      ~indentCellComponent: 'any_rgjq=?,
      ~indentColumnWidth: 'number_a=?,
      ~showColumnsWhenGrouped: Js.boolean=?,
      ~columnExtensions: array(typeR4jx)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableGroupRow"]
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
                 "row": 'any_roan,
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
                   "getCellValue": ('any_rx33, string) => 'any_rly6,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rrn8,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rw5x,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_ryy9, string) => 'any_rn5r,
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
                 "row": 'any_rzhd,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rili,
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
                 "row": 'any_rlg6,
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
                   "getCellValue": ('any_rpjf, string) => 'any_ras8,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_r6sc,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rv92,
               },
               "column": 'any_rxlb,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~showColumnsWhenGrouped: option(bool)=?,
        ~columnExtensions: option(array(typeR4jx))=?,
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
  type align_rypf = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type sortingDirection_rrae = [
    | [@bs.as "asc"] `Asc
    | [@bs.as "desc"] `Desc
  ];
  [@bs.deriving jsConverter]
  type rjma_rt03 = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
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
      ~cellComponent: 'any_ranz=?,
      ~rowComponent: 'any_rucp=?,
      ~messages: 'any_r3sz=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableHeaderRow"]
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
                 "row": 'any_rcr8,
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
                   "getCellValue": ('any_rqjt, string) => 'any_rwyg,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rypf,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r25d, string) => 'any_r6qn,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection_rrae,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_rzvs) | `Enum(rjma_rt03)],
                   "keepOther": bool,
                 } =>
                 unit,
               "showGroupingControls": bool,
               "groupingEnabled": bool,
               "onGroup": unit => unit,
               "resizingEnabled": bool,
               "onWidthChange": 'any_rx71 => unit,
               "onWidthDraft": 'any_roac => unit,
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

module TableRowDetail = {
  [@bs.deriving jsConverter]
  type align_ro9n = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rt0a = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~contentComponent: 'any_r2mv=?,
      ~toggleCellComponent: 'any_rhr6=?,
      ~cellComponent: 'any_ruoz=?,
      ~rowComponent: 'any_r5ce=?,
      ~toggleColumnWidth: 'number_l=?,
      ~rowHeight: 'number_8=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableRowDetail"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_r6hf} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ru50,
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
                   "getCellValue": ('any_rrfz, string) => 'any_rm0u,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_ro9n,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rqrm,
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
                 "row": 'any_rq88,
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
                   "getCellValue": ('any_ra29, string) => 'any_rwnk,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rt0a,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rjns,
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
                 "row": 'any_rcor,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_r1kx,
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
  type align_rrrd = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rmdg = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~headerCellComponent: 'any_r1k1=?,
      ~cellComponent: 'any_rvfz=?,
      ~rowComponent: 'any_rrpx=?,
      ~highlightRow: Js.boolean=?,
      ~selectByRowClick: Js.boolean=?,
      ~showSelectAll: Js.boolean=?,
      ~showSelectionColumn: Js.boolean=?,
      ~selectionColumnWidth: 'number_c=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/TableSelection"]
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
                 "row": 'any_rk5l,
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
                   "getCellValue": ('any_ra4y, string) => 'any_rfqz,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rrrd,
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
                 "row": 'any_rp8g,
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
                   "getCellValue": ('any_rrnj, string) => 'any_re2h,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rmdg,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rg53,
               "selected": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option('any_rrpx)=?,
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
  type align_rex5 = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rurx = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_rz5t = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type align_r6ge = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  type typeRilb;
  [@bs.obj]
  external makeRilb :
    (~columnName: string, ~width: 'number_v=?, ~align: align_r6ge=?, unit) => _ =
    "";
  [@bs.get_index] external getFromRilb : (typeRilb, string) => 'a = "";
  let convertRilb = (madeObj: typeRilb) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(returnObj, "columnName", getFromRilb(madeObj, "columnName"));
    Js.Dict.set(returnObj, "width", getFromRilb(madeObj, "width"));
    Js.Dict.set(returnObj, "align", getFromRilb(madeObj, "align"));
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
      ~layoutComponent: 'any_rgiq=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_rxx1=?,
      ~rowComponent: 'any_rpm0=?,
      ~noDataCellComponent: 'any_rpi3=?,
      ~noDataRowComponent: 'any_r1oh=?,
      ~stubCellComponent: 'any_rz1r=?,
      ~stubHeaderCellComponent: 'any_r1nq=?,
      ~columnExtensions: array(typeRilb)=?,
      ~messages: 'any_rd9h=?,
      ~fixedHeaderComponent: 'any_ry5z=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/Table"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~layoutComponent: option('any_rgiq)=?,
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
                 "row": 'any_rysh,
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
                   "getCellValue": ('any_rrm6, string) => 'any_rzwg,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rex5,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rnih,
               "row": 'any_rdbp,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r5kn, string) => 'any_rdi4,
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
                 "row": 'any_rxut,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rwcb,
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
                 "row": 'any_r0y5,
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
                 "row": 'any_rouz,
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
                   "getCellValue": ('any_rhv3, string) => 'any_rboq,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rurx,
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
                 "row": 'any_r2ap,
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
                   "getCellValue": ('any_rgsq, string) => 'any_rypl,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align_rz5t,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(typeRilb))=?,
        ~messages: option(typeMessages)=?,
        ~fixedHeaderComponent: option('any_ry5z)=?,
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
      ~rootComponent: 'any_rsj4=?,
      ~flexibleSpaceComponent: 'any_r6vr=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/Toolbar"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~flexibleSpaceComponent: option('any_r6vr)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~rootComponent?, ~flexibleSpaceComponent?, ()),
      children,
    );
};

module VirtualTable = {
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
      ~estimatedRowHeight: 'number_c=?,
      ~height: 'number_m=?,
      ~messages: 'any_rjkq=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui/VirtualTable"]
  external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~estimatedRowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~height: option([ | `Int(int) | `Float(float)])=?,
        ~messages: option(typeMessages)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~estimatedRowHeight=?
            Js.Option.map((. v) => unwrapValue(v), estimatedRowHeight),
          ~height=?Js.Option.map((. v) => unwrapValue(v), height),
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};
