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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      showColumnChooser: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. showColumnChooser) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("showColumnChooser", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~overlayComponent: 'any_r3rx=?,
      ~containerComponent: 'any_rlfv=?,
      ~itemComponent: 'any_rmni=?,
      ~toggleButtonComponent: 'any_redj=?,
      ~messages: 'any_rc3c=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "ColumnChooser";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_rjfz,
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
                   "getCellValue": ('any_r3oh, string) => 'any_ret4,
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
               "buttonRef": 'any_rc89 => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module DragDropProvider = {
  [@bs.obj]
  external makeProps :
    (~containerComponent: 'any_rk9b=?, ~columnComponent: 'any_rbxj=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "getCellValue": ('any_r8lv, string) => 'any_rb8v,
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
  module Columns = {
    [@bs.deriving abstract]
    type t('any_r8os, 'any_r37g) = {
      name: string,
      [@bs.optional]
      title: string,
      [@bs.optional]
      getCellValue: ('any_r8os, string) => 'any_r37g,
    };
    let make = t;
    let unwrap = (obj: t('any_r8os, 'any_r37g)) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap |. Js.Dict.set("name", obj |. name |. toJsUnsafe);
      switch (obj |. title) {
      | Some(v) => unwrappedMap |. Js.Dict.set("title", v |. toJsUnsafe)
      | None => ()
      };
      switch (obj |. getCellValue) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("getCellValue", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~rows: array('any_rc6h)=?,
      ~getRowId: 'any_rr5d=?,
      ~getCellValue: 'any_rsif=?,
      ~columns: array(Columns.t('any_r8os, 'any_r37g))=?,
      ~rootComponent: 'any_ribo=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rc6h))=?,
        ~getRowId:
           option(
             'any_rrcq => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_risa, string) => 'any_rhgk)=?,
        ~columns: option(array(Columns.t('any_r8os, 'any_r37g)))=?,
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
                Js.Array.map(item => toJsUnsafe(Columns.unwrap(item)), v),
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      groupByColumn: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. groupByColumn) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("groupByColumn", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~layoutComponent: 'genericCallback=?,
      ~containerComponent: 'any_rrym=?,
      ~itemComponent: 'any_rg00=?,
      ~emptyMessageComponent: 'any_revr=?,
      ~messages: 'any_raim=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                   "getCellValue": ('any_rig0, string) => 'any_rntu,
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
                   "direction": [ | `Any('any_rmmh) | `Enum(direction_enum)],
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
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module PagingPanel = {
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      showAll: string,
      [@bs.optional]
      rowsPerPage: string,
      [@bs.optional]
      info:
        {
          .
          "from": [ | `Int(int) | `Float(float)],
          "to": [ | `Int(int) | `Float(float)],
          "count": [ | `Int(int) | `Float(float)],
        } =>
        [ | `String(string) | `String(string)],
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. showAll) {
        | Some(v) => unwrappedMap |. Js.Dict.set("showAll", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. rowsPerPage) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("rowsPerPage", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. info) {
        | Some(v) => unwrappedMap |. Js.Dict.set("info", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~pageSizes: 'arrayOf_rxy4=?,
      ~containerComponent: 'any_r6kz=?,
      ~messages: 'any_rpcw=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
        ~messages: option(Messages.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~pageSizes?,
          ~containerComponent?,
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module SearchPanel = {
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      searchPlaceholder: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. searchPlaceholder) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("searchPlaceholder", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (~inputComponent: 'any_ru47=?, ~messages: 'any_rvp9=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
        ~messages: option(Messages.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~inputComponent?,
          ~messages=?Messages.unwrap(messages),
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
      ~columnBands: array('any_ryb3)=?,
      ~cellComponent: 'any_rq0l=?,
      ~rowComponent: 'any_rg24=?,
      ~bandedHeaderCellComponent: 'genericCallback=?,
      ~invisibleCellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "TableBandHeader";
  let make =
      (
        ~columnBands: option(array('any_ryb3))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rkj8,
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
                   "getCellValue": ('any_ro2h, string) => 'any_r2z0,
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
      ~onOrderChange: 'any_rp4z=?,
      ~tableContainerComponent: 'genericCallback=?,
      ~rowComponent: 'genericCallback=?,
      ~cellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
  module DefaultColumnWidths = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      width: [ | `Int(int) | `Float(float)],
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("width", unwrapValue(obj |. width) |. toJsUnsafe);
      unwrappedMap;
    };
  };
  module ColumnWidths = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      width: [ | `Int(int) | `Float(float)],
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("width", unwrapValue(obj |. width) |. toJsUnsafe);
      unwrappedMap;
    };
  };
  module NextColumnWidths = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      width: [ | `Int(int) | `Float(float)],
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("width", unwrapValue(obj |. width) |. toJsUnsafe);
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~defaultColumnWidths: array(DefaultColumnWidths.t)=?,
      ~columnWidths: array(ColumnWidths.t)=?,
      ~onColumnWidthsChange: 'any_rla1=?,
      ~minColumnWidth: 'number_9=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "TableColumnResizing";
  let make =
      (
        ~defaultColumnWidths: option(array(DefaultColumnWidths.t))=?,
        ~columnWidths: option(array(ColumnWidths.t))=?,
        ~onColumnWidthsChange: option(array(NextColumnWidths.t) => unit)=?,
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
                  item => toJsUnsafe(DefaultColumnWidths.unwrap(item)),
                  v,
                ),
              defaultColumnWidths,
            ),
          ~columnWidths=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnWidths.unwrap(item)),
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      noColumns: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. noColumns) {
        | Some(v) => unwrappedMap |. Js.Dict.set("noColumns", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      togglingEnabled: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      unwrappedMap
      |. Js.Dict.set("togglingEnabled", obj |. togglingEnabled |. toJsUnsafe);
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~hiddenColumnNames: array(string)=?,
      ~defaultHiddenColumnNames: array(string)=?,
      ~emptyMessageComponent: 'any_rrta=?,
      ~onHiddenColumnNamesChange: 'any_rk3j=?,
      ~messages: 'any_rrxp=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~columnTogglingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
        ~messages: option(Messages.t)=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
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
          ~messages=?Messages.unwrap(messages),
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      addCommand: string,
      [@bs.optional]
      editCommand: string,
      [@bs.optional]
      deleteCommand: string,
      [@bs.optional]
      commitCommand: string,
      [@bs.optional]
      cancelCommand: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. addCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("addCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. editCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("editCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. deleteCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("deleteCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. commitCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("commitCommand", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. cancelCommand) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("cancelCommand", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rjy9=?,
      ~headerCellComponent: 'any_r75q=?,
      ~commandComponent: 'any_rhm1=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_renv=?,
      ~messages: 'any_rfph=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rmtn,
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
                   "getCellValue": ('any_rnxd, string) => 'any_rnou,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rq0m,
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
                 "row": 'any_rke3,
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
                   "getCellValue": ('any_rpjh, string) => 'any_r8rt,
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
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
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
      ~rowHeight: 'number_1=?,
      ~cellComponent: 'any_rgvk=?,
      ~rowComponent: 'any_rdn7=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_r3ce,
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
                   "getCellValue": ('any_rv4z, string) => 'any_rdye,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r5si,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rc9q, string) => 'any_r477,
               },
               "value": 'any_rph5,
               "editingEnabled": bool,
               "onValueChange": 'any_rkzw => unit,
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
                 "row": 'any_r6yv,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rno5,
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      filterPlaceholder: string,
      [@bs.optional]
      contains: string,
      [@bs.optional]
      notContains: string,
      [@bs.optional]
      startsWith: string,
      [@bs.optional]
      endsWith: string,
      [@bs.optional]
      equal: string,
      [@bs.optional]
      notEqual: string,
      [@bs.optional]
      greaterThan: string,
      [@bs.optional]
      greaterThanOrEqual: string,
      [@bs.optional]
      lessThan: string,
      [@bs.optional]
      lessThanOrEqual: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. filterPlaceholder) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("filterPlaceholder", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. contains) {
        | Some(v) => unwrappedMap |. Js.Dict.set("contains", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. notContains) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("notContains", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. startsWith) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("startsWith", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. endsWith) {
        | Some(v) => unwrappedMap |. Js.Dict.set("endsWith", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. equal) {
        | Some(v) => unwrappedMap |. Js.Dict.set("equal", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. notEqual) {
        | Some(v) => unwrappedMap |. Js.Dict.set("notEqual", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. greaterThan) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("greaterThan", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. greaterThanOrEqual) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("greaterThanOrEqual", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. lessThan) {
        | Some(v) => unwrappedMap |. Js.Dict.set("lessThan", v |. toJsUnsafe)
        | None => ()
        };
        switch (obj |. lessThanOrEqual) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("lessThanOrEqual", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
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
      ~rowHeight: 'number_t=?,
      ~showFilterSelector: bool=?,
      ~messages: 'any_ryj2=?,
      ~cellComponent: 'any_r38t=?,
      ~rowComponent: 'any_rnfq=?,
      ~filterSelectorComponent: 'any_rbgd=?,
      ~iconComponent: 'any_rntl=?,
      ~editorComponent: 'any_r88t=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "TableFilterRow";
  let make =
      (
        ~rowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~showFilterSelector: option(bool)=?,
        ~messages: option(Messages.t)=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r65i,
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
                   "getCellValue": ('any_r3q5, string) => 'any_r1uu,
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
                 "getCellValue": ('any_ri5e, string) => 'any_rllf,
               },
               "filteringEnabled": bool,
               "getMessage": string => string,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~rowComponent: option(Js.t({..}) => ReasonReact.reactElement)=?,
        ~filterSelectorComponent:
           option(
             {
               .
               "iconComponent":
                 {. "type": string} => ReasonReact.reactElement,
               "value": string,
               "availableValues": array(string),
               "onChange": string => unit,
             } =>
             ReasonReact.reactElement,
           )=?,
        ~iconComponent:
           option({. "type": string} => ReasonReact.reactElement)=?,
        ~editorComponent:
           option(
             {
               .
               "value": 'any_rixm,
               "disabled": bool,
               "onChange": string => unit,
               "getMessage": string => string,
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
          ~showFilterSelector?,
          ~messages=?Messages.unwrap(messages),
          ~cellComponent?,
          ~rowComponent?,
          ~filterSelectorComponent?,
          ~iconComponent?,
          ~editorComponent?,
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
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      [@bs.optional]
      showWhenGrouped: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (obj |. showWhenGrouped) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("showWhenGrouped", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  [@bs.obj]
  external makeProps :
    (
      ~cellComponent: 'any_rr2t=?,
      ~rowComponent: 'any_rpo8=?,
      ~indentCellComponent: 'any_rfou=?,
      ~indentColumnWidth: 'number_6=?,
      ~showColumnsWhenGrouped: bool=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_r7ya,
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
                   "getCellValue": ('any_r4p2, string) => 'any_rues,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rkm6,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rpnk, string) => 'any_rlhb,
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
                 "row": 'any_rqdw,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rkrz,
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
                 "row": 'any_rpf2,
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
                   "getCellValue": ('any_r3zj, string) => 'any_rqfd,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rh4b,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r85c, string) => 'any_rfdx,
               },
             } =>
             ReasonReact.reactElement,
           )=?,
        ~indentColumnWidth: option([ | `Int(int) | `Float(float)])=?,
        ~showColumnsWhenGrouped: option(bool)=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
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
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      sortingHint: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. sortingHint) {
        | Some(v) =>
          unwrappedMap |. Js.Dict.set("sortingHint", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~showSortingControls: bool=?,
      ~showGroupingControls: bool=?,
      ~cellComponent: 'any_raxr=?,
      ~rowComponent: 'any_r2mr=?,
      ~messages: 'any_rmr6=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_r7g4,
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
                   "getCellValue": ('any_rbgf, string) => 'any_rmv3,
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
                 "getCellValue": ('any_r8qn, string) => 'any_razs,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_rua8) | `Enum(direction_enum)],
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
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
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
      ~contentComponent: 'any_rsz7=?,
      ~toggleCellComponent: 'any_rkhd=?,
      ~cellComponent: 'any_rhn7=?,
      ~rowComponent: 'any_r76x=?,
      ~toggleColumnWidth: 'number_e=?,
      ~rowHeight: 'number_9=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_royw} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r6x8,
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
                   "getCellValue": ('any_r6cv, string) => 'any_rovt,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r1ua,
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
                 "row": 'any_r4cb,
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
                   "getCellValue": ('any_r6r8, string) => 'any_rn8i,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rvsc,
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
                 "row": 'any_rzea,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rjlc,
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
      ~headerCellComponent: 'any_ruqd=?,
      ~cellComponent: 'any_rxab=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_4=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rrvj,
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
                   "getCellValue": ('any_rq4y, string) => 'any_rrly,
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
                 "row": 'any_ru8j,
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
                   "getCellValue": ('any_rq0l, string) => 'any_r23b,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rjf8,
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
      ~cellComponent: 'any_r65j=?,
      ~indentComponent: 'any_rkc5=?,
      ~expandButtonComponent: 'any_rwt2=?,
      ~checkboxComponent: 'any_r1uk=?,
      ~contentComponent: 'any_rydl=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "TableTreeColumn";
  let make =
      (
        ~for_: option(string)=?,
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
                 "row": 'any_rhl9,
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
                   "getCellValue": ('any_rseq, string) => 'any_rij2,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_r1f6,
               "row": 'any_re9r,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rnff, string) => 'any_r8yi,
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
          ~_for=?for_,
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
  module ColumnExtensions = {
    [@bs.deriving abstract]
    type t = {
      columnName: string,
      [@bs.optional]
      width: [ | `Int(int) | `Float(float)],
      [@bs.optional]
      align,
      [@bs.optional]
      wordWrapEnabled: bool,
    };
    let make = t;
    let unwrap = (obj: t) => {
      let unwrappedMap = Js.Dict.empty();
      unwrappedMap
      |. Js.Dict.set("columnName", obj |. columnName |. toJsUnsafe);
      switch (Js.Option.map((. v) => unwrapValue(v), obj |. width)) {
      | Some(v) => unwrappedMap |. Js.Dict.set("width", v |. toJsUnsafe)
      | None => ()
      };
      switch (Js.Option.map((. v) => alignToJs(v), obj |. align)) {
      | Some(v) => unwrappedMap |. Js.Dict.set("align", v |. toJsUnsafe)
      | None => ()
      };
      switch (obj |. wordWrapEnabled) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("wordWrapEnabled", v |. toJsUnsafe)
      | None => ()
      };
      unwrappedMap;
    };
  };
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      noData: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. noData) {
        | Some(v) => unwrappedMap |. Js.Dict.set("noData", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~layoutComponent: 'genericCallback=?,
      ~tableComponent: ReasonReact.reactElement=?,
      ~headComponent: ReasonReact.reactElement=?,
      ~bodyComponent: ReasonReact.reactElement=?,
      ~containerComponent: ReasonReact.reactElement=?,
      ~cellComponent: 'any_rnlr=?,
      ~rowComponent: 'any_rrmi=?,
      ~noDataCellComponent: 'any_rqzw=?,
      ~noDataRowComponent: 'any_r3vs=?,
      ~stubRowComponent: 'any_r8no=?,
      ~stubCellComponent: 'any_r1hs=?,
      ~stubHeaderCellComponent: 'any_rm6a=?,
      ~columnExtensions: array(ColumnExtensions.t)=?,
      ~messages: 'any_r8vz=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
                 "row": 'any_rr6s,
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
                   "getCellValue": ('any_ra1t, string) => 'any_rk67,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_riq3,
               "row": 'any_rj6t,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rn0c, string) => 'any_rzu3,
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
                 "row": 'any_rjxx,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rqoa,
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
                 "row": 'any_rz7l,
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
                   "getCellValue": ('any_rm7x, string) => 'any_r904,
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
                 "row": 'any_rwk2,
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
                 "row": 'any_rvs0,
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
                 "row": 'any_roze,
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
                   "getCellValue": ('any_rqfw, string) => 'any_r9ef,
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
                 "row": 'any_rj3v,
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
                   "getCellValue": ('any_rkx9, string) => 'any_rjfz,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
             } =>
             ReasonReact.reactElement,
           )=?,
        ~columnExtensions: option(array(ColumnExtensions.t))=?,
        ~messages: option(Messages.t)=?,
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
                  item => toJsUnsafe(ColumnExtensions.unwrap(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};

module Toolbar = {
  [@bs.obj]
  external makeProps :
    (
      ~rootComponent: 'any_ru56=?,
      ~flexibleSpaceComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
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
  module Messages = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      noData: string,
    };
    let make = t;
    let unwrap = (obj: option(t)) =>
      switch (obj) {
      | Some(obj) =>
        let unwrappedMap = Js.Dict.empty();
        switch (obj |. noData) {
        | Some(v) => unwrappedMap |. Js.Dict.set("noData", v |. toJsUnsafe)
        | None => ()
        };
        Some(unwrappedMap);
      | None => None
      };
  };
  [@bs.obj]
  external makeProps :
    (
      ~estimatedRowHeight: 'number_y=?,
      ~height: 'number_8=?,
      ~headTableComponent: 'genericCallback=?,
      ~messages: 'any_r3jn=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid-bootstrap4"]
  external reactClass : ReasonReact.reactClass = "VirtualTable";
  let make =
      (
        ~estimatedRowHeight: option([ | `Int(int) | `Float(float)])=?,
        ~height: option([ | `Int(int) | `Float(float)])=?,
        ~headTableComponent: option('genericCallback)=?,
        ~messages: option(Messages.t)=?,
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
          ~messages=?Messages.unwrap(messages),
          (),
        ),
      children,
    );
};
