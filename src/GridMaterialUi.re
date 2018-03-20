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
  external makeMessages : (~showColumnChooser: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "showColumnChooser",
        toJsUnsafe(getFromMessages(madeObj, "showColumnChooser")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~overlayComponent: 'any_rhho=?,
      ~containerComponent: 'any_ramw=?,
      ~itemComponent: 'any_rcpe=?,
      ~toggleButtonComponent: 'any_rkk8=?,
      ~messages: 'any_rbkx=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "ColumnChooser";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_rucq,
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
                   "getCellValue": ('any_r2pw, string) => 'any_rtce,
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
               "buttonRef": 'any_ruyx => unit,
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
    (~containerComponent: 'any_r699=?, ~columnComponent: 'any_rxuc=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "DragDropProvider";
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
                 "getCellValue": ('any_rd35, string) => 'any_r48d,
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
  type typeColumns;
  [@bs.obj]
  external makeColumns :
    (~name: string, ~title: string=?, ~getCellValue: 'any_rvgq=?, unit) =>
    typeColumns =
    "";
  [@bs.get_index] external getFromColumns : (typeColumns, string) => 'a = "";
  let convertColumns = (madeObj: typeColumns) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "name",
      toJsUnsafe(getFromColumns(madeObj, "name")),
    );
    Js.Dict.set(
      returnObj,
      "title",
      toJsUnsafe(getFromColumns(madeObj, "title")),
    );
    Js.Dict.set(
      returnObj,
      "getCellValue",
      toJsUnsafe(getFromColumns(madeObj, "getCellValue")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~rows: array('any_rm01)=?,
      ~getRowId: 'any_rds2=?,
      ~getCellValue: 'any_rlbh=?,
      ~columns: array(typeColumns)=?,
      ~rootComponent: 'any_r725=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rm01))=?,
        ~getRowId:
           option(
             'any_rm6x => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_ry48, string) => 'any_rniu)=?,
        ~columns: option(array(typeColumns))=?,
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
          ~rows=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              rows,
            ),
          ~getRowId?,
          ~getCellValue?,
          ~columns=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertColumns(item)), v),
              columns,
            ),
          ~rootComponent?,
          (),
        ),
      children,
    );
};

module GroupingPanel = {
  [@bs.deriving jsConverter]
  type sortingDirection = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  [@bs.deriving jsConverter]
  type rysz = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~groupByColumn: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "groupByColumn",
        toJsUnsafe(getFromMessages(madeObj, "groupByColumn")),
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
      ~layoutComponent: 'any_rjol=?,
      ~containerComponent: 'any_reuj=?,
      ~itemComponent: 'any_r1u0=?,
      ~emptyMessageComponent: 'any_rmfp=?,
      ~messages: 'any_rfy2=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "GroupingPanel";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~layoutComponent: option('any_rjol)=?,
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
                   "getCellValue": ('any_r42f, string) => 'any_rf7f,
                 },
                 "draft": string,
               },
               "showGroupingControls": bool,
               "showSortingControls": bool,
               "groupingEnabled": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {. "direction": [ | `Any('any_r0qx) | `Enum(rysz)]} => unit,
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
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_reuk=?, unit) =>
    typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "showAll",
        toJsUnsafe(getFromMessages(madeObj, "showAll")),
      );
      Js.Dict.set(
        returnObj,
        "rowsPerPage",
        toJsUnsafe(getFromMessages(madeObj, "rowsPerPage")),
      );
      Js.Dict.set(
        returnObj,
        "info",
        toJsUnsafe(getFromMessages(madeObj, "info")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~pageSizes: 'arrayOf_rouu=?,
      ~containerComponent: 'any_rel6=?,
      ~messages: 'any_ry1b=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "PagingPanel";
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
  external makeMessages : (~searchPlaceholder: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "searchPlaceholder",
        toJsUnsafe(getFromMessages(madeObj, "searchPlaceholder")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (~inputComponent: 'any_rkc8=?, ~messages: 'any_rpz6=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "SearchPanel";
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
      ~onOrderChange: 'any_ryis=?,
      ~tableContainerComponent: 'any_rlqc=?,
      ~rowComponent: 'any_rcbx=?,
      ~cellComponent: 'any_r9gx=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableColumnReordering";
  let make =
      (
        ~order: option(array(string))=?,
        ~defaultOrder: option(array(string))=?,
        ~onOrderChange: option(array(string) => unit)=?,
        ~tableContainerComponent: option('any_rlqc)=?,
        ~rowComponent: option('any_rcbx)=?,
        ~cellComponent: option('any_r9gx)=?,
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
  type typeDefaultColumnWidths;
  [@bs.obj]
  external makeDefaultColumnWidths :
    (~columnName: string, ~width: 'number_e, unit) => typeDefaultColumnWidths =
    "";
  [@bs.get_index]
  external getFromDefaultColumnWidths : (typeDefaultColumnWidths, string) => 'a =
    "";
  let convertDefaultColumnWidths = (madeObj: typeDefaultColumnWidths) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultColumnWidths(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "width",
      toJsUnsafe(unwrapValue(getFromDefaultColumnWidths(madeObj, "width"))),
    );
    returnObj;
  };
  type typeColumnWidths;
  [@bs.obj]
  external makeColumnWidths :
    (~columnName: string, ~width: 'number_2, unit) => typeColumnWidths =
    "";
  [@bs.get_index]
  external getFromColumnWidths : (typeColumnWidths, string) => 'a = "";
  let convertColumnWidths = (madeObj: typeColumnWidths) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnWidths(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "width",
      toJsUnsafe(unwrapValue(getFromColumnWidths(madeObj, "width"))),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(typeDefaultColumnWidths)=?,
      ~columnWidths: array(typeColumnWidths)=?,
      ~onColumnWidthsChange: 'any_r140=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableColumnResizing";
  let make =
      (
        ~defaultColumnWidths: option(array(typeDefaultColumnWidths))=?,
        ~columnWidths: option(array(typeColumnWidths))=?,
        ~onColumnWidthsChange: option(Js.t({..}) => unit)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~defaultColumnWidths=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultColumnWidths(item)),
                  v,
                ),
              defaultColumnWidths,
            ),
          ~columnWidths=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnWidths(item)),
                  v,
                ),
              columnWidths,
            ),
          ~onColumnWidthsChange?,
          (),
        ),
      children,
    );
};

module TableColumnVisibility = {
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~noColumns: string=?, unit) => typeMessages = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "noColumns",
        toJsUnsafe(getFromMessages(madeObj, "noColumns")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~togglingEnabled: Js.boolean, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "togglingEnabled",
      toJsUnsafe(
        Js.Boolean.to_js_boolean(
          getFromColumnExtensions(madeObj, "togglingEnabled"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_rtki=?,
      ~onHiddenColumnNamesChange: 'any_r6rk=?,
      ~messages: 'any_rgcc=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnTogglingEnabled: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableColumnVisibility";
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
        ~columnExtensions: option(array(typeColumnExtensions))=?,
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
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
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
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type id = [
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
    typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "addCommand",
        toJsUnsafe(getFromMessages(madeObj, "addCommand")),
      );
      Js.Dict.set(
        returnObj,
        "editCommand",
        toJsUnsafe(getFromMessages(madeObj, "editCommand")),
      );
      Js.Dict.set(
        returnObj,
        "deleteCommand",
        toJsUnsafe(getFromMessages(madeObj, "deleteCommand")),
      );
      Js.Dict.set(
        returnObj,
        "commitCommand",
        toJsUnsafe(getFromMessages(madeObj, "commitCommand")),
      );
      Js.Dict.set(
        returnObj,
        "cancelCommand",
        toJsUnsafe(getFromMessages(madeObj, "cancelCommand")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rn55=?,
      ~headerCellComponent: 'any_rllm=?,
      ~commandComponent: 'any_rkoc=?,
      ~showAddCommand: Js.boolean=?,
      ~showEditCommand: Js.boolean=?,
      ~showDeleteCommand: Js.boolean=?,
      ~width: 'union_r488=?,
      ~messages: 'any_rz4u=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableEditColumn";
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
                 "row": 'any_r4w8,
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
                   "getCellValue": ('any_rxk8, string) => 'any_r4zd,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rw6i,
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
                 "row": 'any_rofa,
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
                   "getCellValue": ('any_rq8p, string) => 'any_r4xc,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
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
               "id": id,
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
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_f=?,
      ~cellComponent: 'any_rboe=?,
      ~rowComponent: 'any_ru9j=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableEditRow";
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
                 "row": 'any_rp54,
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
                   "getCellValue": ('any_ra2b, string) => 'any_rp7u,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rc4o,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rxz1, string) => 'any_reod,
               },
               "value": 'any_rk1y,
               "editingEnabled": bool,
               "onValueChange": 'any_rrh7 => unit,
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
                 "row": 'any_rnnm,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rrdw,
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
  external makeMessages : (~filterPlaceholder: string=?, unit) => typeMessages =
    "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "filterPlaceholder",
        toJsUnsafe(getFromMessages(madeObj, "filterPlaceholder")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~rowHeight: 'number_8=?,
      ~messages: 'any_rmp0=?,
      ~cellComponent: 'any_r8l6=?,
      ~rowComponent: 'any_ryem=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableFilterRow";
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
                 "row": 'any_rffj,
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
                   "getCellValue": ('any_rzl6, string) => 'any_rmoc,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
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
                 "getCellValue": ('any_rfrl, string) => 'any_rvqo,
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
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~showWhenGrouped: Js.boolean=?, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "showWhenGrouped",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Boolean.to_js_boolean(v),
          getFromColumnExtensions(madeObj, "showWhenGrouped"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rhq9=?,
      ~rowComponent: 'any_rgy6=?,
      ~indentCellComponent: 'any_r3qd=?,
      ~indentColumnWidth: 'number_p=?,
      ~showColumnsWhenGrouped: Js.boolean=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableGroupRow";
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
                 "row": 'any_r85n,
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
                   "getCellValue": ('any_rsiu, string) => 'any_rl8v,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rpy6,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rnws, string) => 'any_ryly,
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
                 "row": 'any_rksz,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rmvb,
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
                 "row": 'any_rsk2,
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
                   "getCellValue": ('any_r8qy, string) => 'any_rclh,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rz6w,
               },
               "column": 'any_r5hb,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~showColumnsWhenGrouped: option(bool)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
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
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          (),
        ),
      children,
    );
};

module TableHeaderRow = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.deriving jsConverter]
  type sortingDirection = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  [@bs.deriving jsConverter]
  type rdgg = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~sortingHint: string=?, unit) => typeMessages = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "sortingHint",
        toJsUnsafe(getFromMessages(madeObj, "sortingHint")),
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
      ~cellComponent: 'any_rzw9=?,
      ~rowComponent: 'any_rsq4=?,
      ~messages: 'any_rmeu=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableHeaderRow";
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
                 "row": 'any_rrm4,
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
                   "getCellValue": ('any_rygb, string) => 'any_r9da,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rq7u, string) => 'any_rsos,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r4lt) | `Enum(rdgg)],
                   "keepOther": bool,
                 } =>
                 unit,
               "showGroupingControls": bool,
               "groupingEnabled": bool,
               "onGroup": unit => unit,
               "resizingEnabled": bool,
               "onWidthChange": 'any_r7u8 => unit,
               "onWidthDraft": 'any_r71w => unit,
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
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~contentComponent: 'any_r6uq=?,
      ~toggleCellComponent: 'any_rv9k=?,
      ~cellComponent: 'any_rrb5=?,
      ~rowComponent: 'any_raca=?,
      ~toggleColumnWidth: 'number_i=?,
      ~rowHeight: 'number_r=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rlcm} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rcb0,
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
                   "getCellValue": ('any_rhtl, string) => 'any_rxkf,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rgfc,
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
                 "row": 'any_rfby,
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
                   "getCellValue": ('any_rhxh, string) => 'any_rhlv,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rara,
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
                 "row": 'any_rn16,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rscs,
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
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~headerCellComponent: 'any_raad=?,
      ~cellComponent: 'any_rac9=?,
      ~rowComponent: 'any_rnrf=?,
      ~highlightRow: Js.boolean=?,
      ~selectByRowClick: Js.boolean=?,
      ~showSelectAll: Js.boolean=?,
      ~showSelectionColumn: Js.boolean=?,
      ~selectionColumnWidth: 'number_0=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "TableSelection";
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
                 "row": 'any_rdmz,
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
                   "getCellValue": ('any_ryek, string) => 'any_rh4h,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
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
                 "row": 'any_rre0,
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
                   "getCellValue": ('any_rrk7, string) => 'any_r7xg,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_raz2,
               "selected": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option('any_rnrf)=?,
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
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~width: 'number_m=?, ~align: align=?, unit) =>
    typeColumnExtensions =
    "";
  [@bs.get_index]
  external getFromColumnExtensions : (typeColumnExtensions, string) => 'a = "";
  let convertColumnExtensions = (madeObj: typeColumnExtensions) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromColumnExtensions(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "width",
      toJsUnsafe(
        Js.Option.map(
          (. v) => unwrapValue(v),
          getFromColumnExtensions(madeObj, "width"),
        ),
      ),
    );
    Js.Dict.set(
      returnObj,
      "align",
      toJsUnsafe(
        Js.Option.map(
          (. v) => alignToJs(v),
          getFromColumnExtensions(madeObj, "align"),
        ),
      ),
    );
    returnObj;
  };
  type typeMessages;
  [@bs.obj]
  external makeMessages : (~noData: string=?, unit) => typeMessages = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "noData",
        toJsUnsafe(getFromMessages(madeObj, "noData")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~layoutComponent: 'any_rqbr=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_r9a6=?,
      ~rowComponent: 'any_r61b=?,
      ~noDataCellComponent: 'any_rnpr=?,
      ~noDataRowComponent: 'any_rovt=?,
      ~stubCellComponent: 'any_rr9p=?,
      ~stubHeaderCellComponent: 'any_rm87=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~messages: 'any_r5e9=?,
      ~fixedHeaderComponent: 'any_rb0u=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "Table";
  let make =
      (
        ~layoutComponent: option('any_rqbr)=?,
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
                 "row": 'any_rcj8,
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
                   "getCellValue": ('any_rn1q, string) => 'any_rb7r,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_ra90,
               "row": 'any_rxbw,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rfmu, string) => 'any_rb3q,
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
                 "row": 'any_reh5,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "style": Js.t({..}),
               "row": 'any_rxej,
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
                 "row": 'any_r4r5,
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
                 "row": 'any_rlek,
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
                   "getCellValue": ('any_rm2j, string) => 'any_rhy8,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
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
                 "row": 'any_rt4x,
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
                   "getCellValue": ('any_rtqf, string) => 'any_rjyw,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "style": Js.t({..}),
               "colSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~messages: option(typeMessages)=?,
        ~fixedHeaderComponent: option('any_rb0u)=?,
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
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
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
      ~rootComponent: 'any_ry7h=?,
      ~flexibleSpaceComponent: 'any_rr19=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "Toolbar";
  let make =
      (
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~flexibleSpaceComponent: option('any_rr19)=?,
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
  [@bs.obj]
  external makeMessages : (~noData: string=?, unit) => typeMessages = "";
  [@bs.get_index] external getFromMessages : (typeMessages, string) => 'a = "";
  let convertMessages = (madeObj: option(typeMessages)) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    switch (madeObj) {
    | Some(madeObj) =>
      Js.Dict.set(
        returnObj,
        "noData",
        toJsUnsafe(getFromMessages(madeObj, "noData")),
      );
      ();
    | None => ()
    };
    Some(returnObj);
  };
  [@bs.obj]
  external makeProps :
    (
      ~estimatedRowHeight: 'number_x=?,
      ~height: 'number_6=?,
      ~messages: 'any_rqt6=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-material-ui"]
  external reactClass : ReasonReact.reactClass = "VirtualTable";
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
