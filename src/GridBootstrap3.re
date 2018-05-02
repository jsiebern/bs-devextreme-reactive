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
      ~overlayComponent: 'any_rcap=?,
      ~containerComponent: 'any_r2n4=?,
      ~itemComponent: 'any_rxfe=?,
      ~toggleButtonComponent: 'any_rc49=?,
      ~messages: 'any_rzgl=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "ColumnChooser";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_ri2i,
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
                   "getCellValue": ('any_rucy, string) => 'any_r82l,
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
               "buttonRef": 'any_rle6 => unit,
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
    (~containerComponent: 'any_r9gs=?, ~columnComponent: 'any_radl=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
                 "getCellValue": ('any_rh75, string) => 'any_rx36,
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
    (~name: string, ~title: string=?, ~getCellValue: 'any_rh01=?, unit) =>
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
      ~rows: array('any_rgpb)=?,
      ~getRowId: 'any_rwty=?,
      ~getCellValue: 'any_rasc=?,
      ~columns: array(typeColumns)=?,
      ~rootComponent: 'any_rxyd=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rgpb))=?,
        ~getRowId:
           option(
             'any_r52h => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_rahd, string) => 'any_r46q)=?,
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
  type direction_enum = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
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
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~layoutComponent: 'genericCallback=?,
      ~containerComponent: 'any_rv93=?,
      ~itemComponent: 'any_r6o0=?,
      ~emptyMessageComponent: 'any_ry9g=?,
      ~messages: 'any_r2im=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "GroupingPanel";
  let make =
      (
        ~showSortingControls: option(bool)=?,
        ~showGroupingControls: option(bool)=?,
        ~layoutComponent: option('genericCallback)=?,
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
                   "getCellValue": ('any_rta4, string) => 'any_r14o,
                 },
                 "draft": string,
               },
               "showGroupingControls": bool,
               "showSortingControls": bool,
               "groupingEnabled": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r0qq) | `Enum(direction_enum)],
                 } =>
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
          ~showSortingControls?,
          ~showGroupingControls?,
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
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_r9ih=?, unit) =>
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
      ~pageSizes: 'arrayOf_rgwz=?,
      ~containerComponent: 'any_rzn5=?,
      ~messages: 'any_ra8k=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
    (~inputComponent: 'any_rzym=?, ~messages: 'any_row4=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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

module TableBandHeader = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~columnBands: array('any_r513)=?,
      ~cellComponent: 'any_r7b5=?,
      ~rowComponent: 'any_rve8=?,
      ~bandedHeaderCellComponent: 'genericCallback=?,
      ~invisibleCellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "TableBandHeader";
  let make =
      (
        ~columnBands: option(array('any_r513))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ru8h,
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
                   "getCellValue": ('any_ruqp, string) => 'any_r8w6,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        ~bandedHeaderCellComponent: option('genericCallback)=?,
        ~invisibleCellComponent: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~columnBands=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              columnBands,
            ),
          ~cellComponent?,
          ~rowComponent?,
          ~bandedHeaderCellComponent?,
          ~invisibleCellComponent?,
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
      ~onOrderChange: 'any_rr4o=?,
      ~tableContainerComponent: 'genericCallback=?,
      ~rowComponent: 'genericCallback=?,
      ~cellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "TableColumnReordering";
  let make =
      (
        ~order: option(array(string))=?,
        ~defaultOrder: option(array(string))=?,
        ~onOrderChange: option(array(string) => unit)=?,
        ~tableContainerComponent: option('genericCallback)=?,
        ~rowComponent: option('genericCallback)=?,
        ~cellComponent: option('genericCallback)=?,
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
    (~columnName: string, ~width: 'number_p, unit) => typeDefaultColumnWidths =
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
    (~columnName: string, ~width: 'number_k, unit) => typeColumnWidths =
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
  type typeNextColumnWidths;
  [@bs.obj]
  external makeNextColumnWidths :
    (~columnName: string, ~width: 'number_v, unit) => typeNextColumnWidths =
    "";
  [@bs.get_index]
  external getFromNextColumnWidths : (typeNextColumnWidths, string) => 'a = "";
  let convertNextColumnWidths = (madeObj: typeNextColumnWidths) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromNextColumnWidths(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "width",
      toJsUnsafe(unwrapValue(getFromNextColumnWidths(madeObj, "width"))),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(typeDefaultColumnWidths)=?,
      ~columnWidths: array(typeColumnWidths)=?,
      ~onColumnWidthsChange: 'any_rork=?,
      ~minColumnWidth: 'number_9=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "TableColumnResizing";
  let make =
      (
        ~defaultColumnWidths: option(array(typeDefaultColumnWidths))=?,
        ~columnWidths: option(array(typeColumnWidths))=?,
        ~onColumnWidthsChange: option(array(typeNextColumnWidths) => unit)=?,
        ~minColumnWidth: option([ | `Int(int) | `Float(float)])=?,
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
          ~minColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), minColumnWidth),
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
    (~columnName: string, ~togglingEnabled: bool, unit) => typeColumnExtensions =
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
      toJsUnsafe(getFromColumnExtensions(madeObj, "togglingEnabled")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_rvn8=?,
      ~onHiddenColumnNamesChange: 'any_r1kl=?,
      ~messages: 'any_ry27=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnTogglingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
          ~columnTogglingEnabled?,
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
      ~cellComponent: 'any_rwiy=?,
      ~headerCellComponent: 'any_rodt=?,
      ~commandComponent: 'any_rqr3=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_rdjy=?,
      ~messages: 'any_rwd5=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
                 "row": 'any_rte5,
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
                   "getCellValue": ('any_rkal, string) => 'any_rlt7,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rug5,
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
                 "row": 'any_rlfb,
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
                   "getCellValue": ('any_rrcm, string) => 'any_r0sd,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
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
          ~showAddCommand?,
          ~showEditCommand?,
          ~showDeleteCommand?,
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
      ~rowHeight: 'number_s=?,
      ~cellComponent: 'any_rxzg=?,
      ~rowComponent: 'any_rllk=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
                 "row": 'any_r86c,
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
                   "getCellValue": ('any_road, string) => 'any_rsr4,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rvt3,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rtpe, string) => 'any_rr12,
               },
               "value": 'any_ra4a,
               "editingEnabled": bool,
               "onValueChange": 'any_r9hw => unit,
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
                 "row": 'any_r2x6,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_r42a,
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
      ~rowHeight: 'number_n=?,
      ~messages: 'any_rtaw=?,
      ~cellComponent: 'any_rldj=?,
      ~rowComponent: 'any_r8t9=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
                 "row": 'any_rokv,
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
                   "getCellValue": ('any_rbca, string) => 'any_rf58,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
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
                 "getCellValue": ('any_rhz8, string) => 'any_rfhv,
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
    (~columnName: string, ~showWhenGrouped: bool=?, unit) =>
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
      toJsUnsafe(getFromColumnExtensions(madeObj, "showWhenGrouped")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rfa4=?,
      ~rowComponent: 'any_r0ek=?,
      ~indentCellComponent: 'any_rgml=?,
      ~indentColumnWidth: 'number_k=?,
      ~showColumnsWhenGrouped: bool=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
                 "row": 'any_rf7v,
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
                   "getCellValue": ('any_rs0t, string) => 'any_r1o8,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_reho,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r86w, string) => 'any_rg8h,
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
                 "row": 'any_rpu8,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rn5u,
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
                 "row": 'any_rnw6,
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
                   "getCellValue": ('any_r7x5, string) => 'any_r9e1,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rdbi,
               },
               "column": 'any_rfm3,
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
          ~showColumnsWhenGrouped?,
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
  type direction_enum = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
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
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~cellComponent: 'any_ri6o=?,
      ~rowComponent: 'any_rwmb=?,
      ~messages: 'any_r9nc=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
                 "row": 'any_rcc3,
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
                   "getCellValue": ('any_r29q, string) => 'any_rcp9,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rq5v, string) => 'any_rf6i,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_rmb1) | `Enum(direction_enum)],
                   "keepOther": bool,
                 } =>
                 unit,
               "showGroupingControls": bool,
               "groupingEnabled": bool,
               "onGroup": unit => unit,
               "resizingEnabled": bool,
               "onWidthChange":
                 {. "shift": [ | `Int(int) | `Float(float)]} => unit,
               "onWidthDraft":
                 {. "shift": [ | `Int(int) | `Float(float)]} => unit,
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
          ~showSortingControls?,
          ~showGroupingControls?,
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
      ~contentComponent: 'any_r4dx=?,
      ~toggleCellComponent: 'any_r1yc=?,
      ~cellComponent: 'any_r71a=?,
      ~rowComponent: 'any_rot4=?,
      ~toggleColumnWidth: 'number_u=?,
      ~rowHeight: 'number_q=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rbny} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rgk0,
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
                   "getCellValue": ('any_r3fm, string) => 'any_rtbt,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rqbe,
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
                 "row": 'any_rr47,
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
                   "getCellValue": ('any_r0q3, string) => 'any_rv4i,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rhs8,
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
                 "row": 'any_rd2s,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rkmf,
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
      ~headerCellComponent: 'any_rjzs=?,
      ~cellComponent: 'any_r7t6=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_8=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
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
                 "row": 'any_rlpz,
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
                   "getCellValue": ('any_r4va, string) => 'any_rvwv,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
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
                 "row": 'any_rw9v,
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
                   "getCellValue": ('any_r7mg, string) => 'any_rhf2,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rjco,
               "selected": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option('genericCallback)=?,
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
          ~highlightRow?,
          ~selectByRowClick?,
          ~showSelectAll?,
          ~showSelectionColumn?,
          ~selectionColumnWidth=?
            Js.Option.map((. v) => unwrapValue(v), selectionColumnWidth),
          (),
        ),
      children,
    );
};

module TableTreeColumn = {
  [@bs.deriving jsConverter]
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~_for: string=?,
      ~showSelectionControls: bool=?,
      ~showSelectAll: bool=?,
      ~cellComponent: 'any_rbhb=?,
      ~indentComponent: 'any_rylz=?,
      ~expandButtonComponent: 'any_rukx=?,
      ~checkboxComponent: 'any_r5bu=?,
      ~contentComponent: 'any_r5s5=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "TableTreeColumn";
  let make =
      (
        ~_for: option(string)=?,
        ~showSelectionControls: option(bool)=?,
        ~showSelectAll: option(bool)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rxug,
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
                   "getCellValue": ('any_rdid, string) => 'any_rqmi,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_r8rn,
               "row": 'any_r8hk,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_ra1m, string) => 'any_rgrz,
               },
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentComponent:
           option(
             {. "level": [ | `Int(int) | `Float(float)]} =>
             ReasonReact.reactElement,
           )=?,
        ~expandButtonComponent:
           option(
             {
               .
               "visible": bool,
               "expanded": bool,
               "onToggle": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~checkboxComponent:
           option(
             {
               .
               "disabled": bool,
               "checked": bool,
               "indeterminate": bool,
               "onChange": unit => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~contentComponent:
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
          ~_for?,
          ~showSelectionControls?,
          ~showSelectAll?,
          ~cellComponent?,
          ~indentComponent?,
          ~expandButtonComponent?,
          ~checkboxComponent?,
          ~contentComponent?,
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
    (
      ~columnName: string,
      ~width: 'number_j=?,
      ~align: align=?,
      ~wordWrapEnabled: bool=?,
      unit
    ) =>
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
    Js.Dict.set(
      returnObj,
      "wordWrapEnabled",
      toJsUnsafe(getFromColumnExtensions(madeObj, "wordWrapEnabled")),
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
      ~layoutComponent: 'genericCallback=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_r1pv=?,
      ~rowComponent: 'any_rxqj=?,
      ~noDataCellComponent: 'any_rs47=?,
      ~noDataRowComponent: 'any_rh1x=?,
      ~stubRowComponent: 'any_r47r=?,
      ~stubCellComponent: 'any_rctx=?,
      ~stubHeaderCellComponent: 'any_reix=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~messages: 'any_rqd8=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "Table";
  let make =
      (
        ~layoutComponent: option('genericCallback)=?,
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
                 "row": 'any_rnp4,
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
                   "getCellValue": ('any_rehs, string) => 'any_refs,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_repy,
               "row": 'any_r9su,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rnh1, string) => 'any_rnvf,
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
                 "row": 'any_rf1k,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rbyw,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~noDataCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rc0c,
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
                   "getCellValue": ('any_r3s5, string) => 'any_rfbd,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
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
                 "row": 'any_rng5,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~stubRowComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rks5,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
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
                 "row": 'any_rnmt,
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
                   "getCellValue": ('any_ry9o, string) => 'any_re44,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
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
                 "row": 'any_rv6w,
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
                   "getCellValue": ('any_rhus, string) => 'any_r97j,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~messages: option(typeMessages)=?,
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
          ~stubRowComponent?,
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
          (),
        ),
      children,
    );
};

module Toolbar = {
  [@bs.obj]
  external makeProps :
    (
      ~rootComponent: 'any_raif=?,
      ~flexibleSpaceComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "Toolbar";
  let make =
      (
        ~rootComponent:
           option(
             {. "children": ReasonReact.reactElement} =>
             ReasonReact.reactElement,
           )=?,
        ~flexibleSpaceComponent: option('genericCallback)=?,
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
      ~estimatedRowHeight: 'number_v=?,
      ~height: 'number_9=?,
      ~headTableComponent: 'genericCallback=?,
      ~messages: 'any_r5xp=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap3"]
  external reactClass : ReasonReact.reactClass = "VirtualTable";
  let make =
      (
        ~estimatedRowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~height: option([ | `Int(int) | `Float(float)])=?,
        ~headTableComponent: option('genericCallback)=?,
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
          ~headTableComponent?,
          ~messages=?convertMessages(messages),
          (),
        ),
      children,
    );
};
