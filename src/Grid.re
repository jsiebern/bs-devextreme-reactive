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
      ~overlayComponent: 'any_ruuy=?,
      ~containerComponent: 'any_r6fo=?,
      ~itemComponent: 'any_r00o=?,
      ~toggleButtonComponent: 'any_rjrw=?,
      ~messages: 'any_rnll=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "ColumnChooser";
  let make =
      (
        ~overlayComponent:
           option(
             {
               .
               "visible": bool,
               "target": 'any_rc05,
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
                   "getCellValue": ('any_rlh7, string) => 'any_rjgw,
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
               "buttonRef": 'any_rr85 => unit,
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
  type typeGrouping;
  [@bs.obj]
  external makeGrouping : (~columnName: string, unit) => typeGrouping = "";
  [@bs.get_index] external getFromGrouping : (typeGrouping, string) => 'a = "";
  let convertGrouping = (madeObj: typeGrouping) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromGrouping(madeObj, "columnName")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~getChildGroups: 'any_rvg6,
      ~grouping: array(typeGrouping)=?,
      ~expandedGroups: 'invalidArrayType_rmbp=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomGrouping";
  let make =
      (
        ~getChildGroups:
           (array('any_ryu2), {. "columnName": string}, array('any_r75o)) =>
           array(array('any_rc4x)),
        ~grouping: option(array(typeGrouping))=?,
        ~expandedGroups: option('invalidArrayType_rmbp)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~getChildGroups,
          ~grouping=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertGrouping(item)), v),
              grouping,
            ),
          ~expandedGroups?,
          (),
        ),
      children,
    );
};

module CustomPaging = {
  [@bs.obj] external makeProps : (~totalCount: 'number_g=?, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomPaging";
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

module CustomTreeData = {
  [@bs.obj] external makeProps : (~getChildRows: 'any_rj0o, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomTreeData";
  let make =
      (
        ~getChildRows:
           ([ | `Any('any_rnvj) | `Any('any_roic)], array('any_rch6)) =>
           array('any_r6u8),
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~getChildRows, ()),
      children,
    );
};

module DataTypeProvider = {
  [@bs.obj]
  external makeProps :
    (
      ~_for: array(string),
      ~formatterComponent: 'any_rylc=?,
      ~editorComponent: 'any_rxa7=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "DataTypeProvider";
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
                 "getCellValue": ('any_rsoz, string) => 'any_rpa1,
               },
               "row": 'any_rypn,
               "value": 'any_rbmf,
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
                 "getCellValue": ('any_r5z3, string) => 'any_romw,
               },
               "row": 'any_rxkr,
               "value": 'any_rfni,
               "onValueChange": 'any_rmrk => unit,
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
    (~containerComponent: 'any_r4s1=?, ~columnComponent: 'any_ru5u=?, unit) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "getCellValue": ('any_rx0g, string) => 'any_rtob,
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
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (
      ~columnName: string,
      ~editingEnabled: bool=?,
      ~createRowChange: 'any_rcn9=?,
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
      "editingEnabled",
      toJsUnsafe(getFromColumnExtensions(madeObj, "editingEnabled")),
    );
    Js.Dict.set(
      returnObj,
      "createRowChange",
      toJsUnsafe(getFromColumnExtensions(madeObj, "createRowChange")),
    );
    returnObj;
  };
  type typeChanges;
  [@bs.obj]
  external makeChanges :
    (
      ~added: array('any_rwh7)=?,
      ~changed: Js.t({..})=?,
      ~deleted: array([ | `Int(int) | `Float(float) | `String(string)])=?,
      unit
    ) =>
    typeChanges =
    "";
  [@bs.get_index] external getFromChanges : (typeChanges, string) => 'a = "";
  let convertChanges = (madeObj: typeChanges) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "added",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Array.map(item => toJsUnsafe(item), v),
          getFromChanges(madeObj, "added"),
        ),
      ),
    );
    Js.Dict.set(
      returnObj,
      "changed",
      toJsUnsafe(getFromChanges(madeObj, "changed")),
    );
    Js.Dict.set(
      returnObj,
      "deleted",
      toJsUnsafe(
        Js.Option.map(
          (. v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
          getFromChanges(madeObj, "deleted"),
        ),
      ),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~createRowChange: 'any_rb1v=?,
      ~columnEditingEnabled: bool=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
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
      ~onEditingRowIdsChange: 'any_r7fm=?,
      ~addedRows: array('any_r4n6)=?,
      ~defaultAddedRows: array('any_rbz9)=?,
      ~onAddedRowsChange: 'any_r0zj=?,
      ~rowChanges: Js.t({..})=?,
      ~defaultRowChanges: Js.t({..})=?,
      ~onRowChangesChange: 'any_rv62=?,
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
      ~onDeletedRowIdsChange: 'any_r1o0=?,
      ~onCommitChanges: 'any_rar3,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "EditingState";
  let make =
      (
        ~createRowChange:
           option(
             (
               'any_ry0o,
               string,
               [ | `String(string) | `Int(int) | `Float(float)]
             ) =>
             'any_rdmf,
           )=?,
        ~columnEditingEnabled: option(bool)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~editingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~defaultEditingRowIds:
           option(array([ | `Int(int) | `Float(float) | `String(string)]))=?,
        ~onEditingRowIdsChange:
           option(
             array([ | `Int(int) | `Float(float) | `String(string)]) =>
             unit,
           )=?,
        ~addedRows: option(array('any_r4n6))=?,
        ~defaultAddedRows: option(array('any_rbz9))=?,
        ~onAddedRowsChange: option(array('any_rqgt) => unit)=?,
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
        ~onCommitChanges: array(typeChanges) => unit,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~createRowChange?,
          ~columnEditingEnabled?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~editingRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              editingRowIds,
            ),
          ~defaultEditingRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultEditingRowIds,
            ),
          ~onEditingRowIdsChange?,
          ~addedRows=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              addedRows,
            ),
          ~defaultAddedRows=?
            Js.Option.map(
              (. v) => Js.Array.map(item => toJsUnsafe(item), v),
              defaultAddedRows,
            ),
          ~onAddedRowsChange?,
          ~rowChanges?,
          ~defaultRowChanges?,
          ~onRowChangesChange?,
          ~deletedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              deletedRowIds,
            ),
          ~defaultDeletedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultDeletedRowIds,
            ),
          ~onDeletedRowIdsChange?,
          ~onCommitChanges,
          (),
        ),
      children,
    );
};

module FilteringState = {
  type typeFilters;
  [@bs.obj]
  external makeFilters :
    (~columnName: string, ~value: string=?, unit) => typeFilters =
    "";
  [@bs.get_index] external getFromFilters : (typeFilters, string) => 'a = "";
  let convertFilters = (madeObj: typeFilters) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromFilters(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "value",
      toJsUnsafe(getFromFilters(madeObj, "value")),
    );
    returnObj;
  };
  type typeDefaultFilters;
  [@bs.obj]
  external makeDefaultFilters :
    (~columnName: string, ~value: string=?, unit) => typeDefaultFilters =
    "";
  [@bs.get_index]
  external getFromDefaultFilters : (typeDefaultFilters, string) => 'a = "";
  let convertDefaultFilters = (madeObj: typeDefaultFilters) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultFilters(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "value",
      toJsUnsafe(getFromDefaultFilters(madeObj, "value")),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~filteringEnabled: bool, unit) =>
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
      "filteringEnabled",
      toJsUnsafe(getFromColumnExtensions(madeObj, "filteringEnabled")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~filters: array(typeFilters)=?,
      ~defaultFilters: array(typeDefaultFilters)=?,
      ~onFiltersChange: 'any_rpt6=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnFilteringEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "FilteringState";
  let make =
      (
        ~filters: option(array(typeFilters))=?,
        ~defaultFilters: option(array(typeDefaultFilters))=?,
        ~onFiltersChange: option(array(typeFilters) => unit)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~columnFilteringEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~filters=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertFilters(item)), v),
              filters,
            ),
          ~defaultFilters=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultFilters(item)),
                  v,
                ),
              defaultFilters,
            ),
          ~onFiltersChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnFilteringEnabled?,
          (),
        ),
      children,
    );
};

module Grid = {
  type typeColumns;
  [@bs.obj]
  external makeColumns :
    (~name: string, ~title: string=?, ~getCellValue: 'any_rlco=?, unit) =>
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
      ~rows: array('any_r2ue)=?,
      ~getRowId: 'any_r53y=?,
      ~getCellValue: 'any_re78=?,
      ~columns: array(typeColumns)=?,
      ~rootComponent: 'any_rrm3=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_r2ue))=?,
        ~getRowId:
           option(
             'any_rrl4 => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_rsoj, string) => 'any_ru23)=?,
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

module GroupPanelLayout = {
  type typeItems;
  [@bs.obj]
  external makeItems :
    (~column: Js.t({..})=?, ~draft: bool=?, unit) => typeItems =
    "";
  [@bs.get_index] external getFromItems : (typeItems, string) => 'a = "";
  let convertItems = (madeObj: typeItems) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "column",
      toJsUnsafe(getFromItems(madeObj, "column")),
    );
    Js.Dict.set(
      returnObj,
      "draft",
      toJsUnsafe(getFromItems(madeObj, "draft")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~items: array(typeItems),
      ~onGroup: 'genericCallback=?,
      ~itemComponent: 'genericCallback,
      ~containerComponent: 'genericCallback,
      ~emptyMessageComponent: 'genericCallback,
      ~draggingEnabled: bool=?,
      ~isColumnGroupingEnabled: 'genericCallback=?,
      ~onGroupDraft: 'genericCallback=?,
      ~onGroupDraftCancel: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupPanelLayout";
  let make =
      (
        ~items: array(typeItems),
        ~onGroup: option('genericCallback)=?,
        ~itemComponent: 'genericCallback,
        ~containerComponent: 'genericCallback,
        ~emptyMessageComponent: 'genericCallback,
        ~draggingEnabled: option(bool)=?,
        ~isColumnGroupingEnabled: option('genericCallback)=?,
        ~onGroupDraft: option('genericCallback)=?,
        ~onGroupDraftCancel: option('genericCallback)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~items=
            Js.Array.map(item => toJsUnsafe(convertItems(item)), items),
          ~onGroup?,
          ~itemComponent,
          ~containerComponent,
          ~emptyMessageComponent,
          ~draggingEnabled?,
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
      ~containerComponent: 'any_rdar=?,
      ~itemComponent: 'any_rlfn=?,
      ~emptyMessageComponent: 'any_runa=?,
      ~messages: 'any_rrj8=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                   "getCellValue": ('any_ricg, string) => 'any_rfqv,
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
                   "direction": [ | `Any('any_ruks) | `Enum(direction_enum)],
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

module GroupingState = {
  type typeGrouping;
  [@bs.obj]
  external makeGrouping : (~columnName: string, unit) => typeGrouping = "";
  [@bs.get_index] external getFromGrouping : (typeGrouping, string) => 'a = "";
  let convertGrouping = (madeObj: typeGrouping) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromGrouping(madeObj, "columnName")),
    );
    returnObj;
  };
  type typeDefaultGrouping;
  [@bs.obj]
  external makeDefaultGrouping :
    (~columnName: string, unit) => typeDefaultGrouping =
    "";
  [@bs.get_index]
  external getFromDefaultGrouping : (typeDefaultGrouping, string) => 'a = "";
  let convertDefaultGrouping = (madeObj: typeDefaultGrouping) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultGrouping(madeObj, "columnName")),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~groupingEnabled: bool, unit) => typeColumnExtensions =
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
      "groupingEnabled",
      toJsUnsafe(getFromColumnExtensions(madeObj, "groupingEnabled")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~grouping: array(typeGrouping)=?,
      ~defaultGrouping: array(typeDefaultGrouping)=?,
      ~onGroupingChange: 'any_r6qd=?,
      ~expandedGroups: 'invalidArrayType_rb4d=?,
      ~defaultExpandedGroups: 'invalidArrayType_r0xu=?,
      ~onExpandedGroupsChange: 'any_rvk9=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnGroupingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "GroupingState";
  let make =
      (
        ~grouping: option(array(typeGrouping))=?,
        ~defaultGrouping: option(array(typeDefaultGrouping))=?,
        ~onGroupingChange: option(array(typeGrouping) => unit)=?,
        ~expandedGroups: option('invalidArrayType_rb4d)=?,
        ~defaultExpandedGroups: option('invalidArrayType_r0xu)=?,
        ~onExpandedGroupsChange: option('invalidArrayType_r73b => unit)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~columnGroupingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~grouping=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertGrouping(item)), v),
              grouping,
            ),
          ~defaultGrouping=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultGrouping(item)),
                  v,
                ),
              defaultGrouping,
            ),
          ~onGroupingChange?,
          ~expandedGroups?,
          ~defaultExpandedGroups?,
          ~onExpandedGroupsChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnGroupingEnabled?,
          (),
        ),
      children,
    );
};

module IntegratedFiltering = {
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~predicate: 'any_rowl=?, unit) =>
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
      "predicate",
      toJsUnsafe(getFromColumnExtensions(madeObj, "predicate")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~columnExtensions: array(typeColumnExtensions)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedFiltering";
  let make =
      (~columnExtensions: option(array(typeColumnExtensions))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
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

module IntegratedGrouping = {
  type typeCriteriaReturn;
  [@bs.obj]
  external makeCriteriaReturn :
    (~key: 'union_r9hs, ~value: 'any_rqpy=?, unit) => typeCriteriaReturn =
    "";
  [@bs.get_index]
  external getFromCriteriaReturn : (typeCriteriaReturn, string) => 'a = "";
  let convertCriteriaReturn = (madeObj: typeCriteriaReturn) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "key",
      toJsUnsafe(unwrapValue(getFromCriteriaReturn(madeObj, "key"))),
    );
    Js.Dict.set(
      returnObj,
      "value",
      toJsUnsafe(getFromCriteriaReturn(madeObj, "value")),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~criteria: 'any_rx23=?, unit) => typeColumnExtensions =
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
      "criteria",
      toJsUnsafe(getFromColumnExtensions(madeObj, "criteria")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~columnExtensions: array(typeColumnExtensions)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedGrouping";
  let make =
      (~columnExtensions: option(array(typeColumnExtensions))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
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

module IntegratedPaging = {
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedPaging";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module IntegratedSelection = {
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedSelection";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module IntegratedSorting = {
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~compare: 'any_ri3a=?, unit) => typeColumnExtensions =
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
      "compare",
      toJsUnsafe(getFromColumnExtensions(madeObj, "compare")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (~columnExtensions: array(typeColumnExtensions)=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "IntegratedSorting";
  let make =
      (~columnExtensions: option(array(typeColumnExtensions))=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
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

module PagingPanel = {
  type typeMessages;
  [@bs.obj]
  external makeMessages :
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_rfmo=?, unit) =>
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
      ~pageSizes: 'arrayOf_rj2p=?,
      ~containerComponent: 'any_rhyd=?,
      ~messages: 'any_rc61=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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

module PagingState = {
  [@bs.obj]
  external makeProps :
    (
      ~pageSize: 'number_h=?,
      ~defaultPageSize: 'number_1=?,
      ~onPageSizeChange: 'any_rudr=?,
      ~currentPage: 'number_y=?,
      ~defaultCurrentPage: 'number_1=?,
      ~onCurrentPageChange: 'any_rupj=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "PagingState";
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
      ~onExpandedRowIdsChange: 'any_rkv5=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "RowDetailState";
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
          ~expandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              expandedRowIds,
            ),
          ~defaultExpandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultExpandedRowIds,
            ),
          ~onExpandedRowIdsChange?,
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
    (~inputComponent: 'any_r6hl=?, ~messages: 'any_rny3=?, unit) => _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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

module SearchState = {
  [@bs.obj]
  external makeProps :
    (
      ~value: string=?,
      ~defaultValue: string=?,
      ~onValueChange: 'any_rmfh=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SearchState";
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
      ~onSelectionChange: 'any_r1xx=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SelectionState";
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
        makeProps(
          ~selection=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              selection,
            ),
          ~defaultSelection=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultSelection,
            ),
          ~onSelectionChange?,
          (),
        ),
      children,
    );
};

module SortingState = {
  [@bs.deriving jsConverter]
  type direction = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];
  type typeSorting;
  [@bs.obj]
  external makeSorting :
    (~columnName: string, ~direction: direction, unit) => typeSorting =
    "";
  [@bs.get_index] external getFromSorting : (typeSorting, string) => 'a = "";
  let convertSorting = (madeObj: typeSorting) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromSorting(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "direction",
      toJsUnsafe(directionToJs(getFromSorting(madeObj, "direction"))),
    );
    returnObj;
  };
  type typeDefaultSorting;
  [@bs.obj]
  external makeDefaultSorting :
    (~columnName: string, ~direction: direction, unit) => typeDefaultSorting =
    "";
  [@bs.get_index]
  external getFromDefaultSorting : (typeDefaultSorting, string) => 'a = "";
  let convertDefaultSorting = (madeObj: typeDefaultSorting) => {
    let returnObj: Js.Dict.t(string) = Js.Dict.empty();
    Js.Dict.set(
      returnObj,
      "columnName",
      toJsUnsafe(getFromDefaultSorting(madeObj, "columnName")),
    );
    Js.Dict.set(
      returnObj,
      "direction",
      toJsUnsafe(
        directionToJs(getFromDefaultSorting(madeObj, "direction")),
      ),
    );
    returnObj;
  };
  type typeColumnExtensions;
  [@bs.obj]
  external makeColumnExtensions :
    (~columnName: string, ~sortingEnabled: bool, unit) => typeColumnExtensions =
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
      "sortingEnabled",
      toJsUnsafe(getFromColumnExtensions(madeObj, "sortingEnabled")),
    );
    returnObj;
  };
  [@bs.obj]
  external makeProps :
    (
      ~sorting: array(typeSorting)=?,
      ~defaultSorting: array(typeDefaultSorting)=?,
      ~onSortingChange: 'any_rfym=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnSortingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "SortingState";
  let make =
      (
        ~sorting: option(array(typeSorting))=?,
        ~defaultSorting: option(array(typeDefaultSorting))=?,
        ~onSortingChange: option(array(typeSorting) => unit)=?,
        ~columnExtensions: option(array(typeColumnExtensions))=?,
        ~columnSortingEnabled: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~sorting=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(convertSorting(item)), v),
              sorting,
            ),
          ~defaultSorting=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertDefaultSorting(item)),
                  v,
                ),
              defaultSorting,
            ),
          ~onSortingChange?,
          ~columnExtensions=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(
                  item => toJsUnsafe(convertColumnExtensions(item)),
                  v,
                ),
              columnExtensions,
            ),
          ~columnSortingEnabled?,
          (),
        ),
      children,
    );
};

module StaticTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~headerRows: array('any_ra8z)=?,
      ~bodyRows: array('any_req5),
      ~columns: array('any_r642),
      ~minWidth: 'number_p,
      ~containerComponent: 'genericCallback,
      ~tableComponent: 'genericCallback,
      ~headComponent: 'genericCallback=?,
      ~bodyComponent: 'genericCallback,
      ~rowComponent: 'genericCallback,
      ~cellComponent: 'genericCallback,
      ~getCellColSpan: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "StaticTableLayout";
  let make =
      (
        ~headerRows: option(array('any_ra8z))=?,
        ~bodyRows: array('any_req5),
        ~columns: array('any_r642),
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~containerComponent: 'genericCallback,
        ~tableComponent: 'genericCallback,
        ~headComponent: option('genericCallback)=?,
        ~bodyComponent: 'genericCallback,
        ~rowComponent: 'genericCallback,
        ~cellComponent: 'genericCallback,
        ~getCellColSpan: 'genericCallback,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~headerRows?,
          ~bodyRows,
          ~columns,
          ~minWidth=unwrapValue(minWidth),
          ~containerComponent,
          ~tableComponent,
          ~headComponent?,
          ~bodyComponent,
          ~rowComponent,
          ~cellComponent,
          ~getCellColSpan,
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
      ~columnBands: array('any_rc0n)=?,
      ~cellComponent: 'any_rvju=?,
      ~rowComponent: 'any_r4yh=?,
      ~bandedHeaderCellComponent: 'genericCallback=?,
      ~invisibleCellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableBandHeader";
  let make =
      (
        ~columnBands: option(array('any_rc0n))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_rntv,
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
                   "getCellValue": ('any_ro3b, string) => 'any_rf0f,
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
      ~onOrderChange: 'any_r3s2=?,
      ~tableContainerComponent: 'genericCallback=?,
      ~rowComponent: 'genericCallback=?,
      ~cellComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
    (~columnName: string, ~width: 'number_q, unit) => typeDefaultColumnWidths =
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
    (~columnName: string, ~width: 'number_h, unit) => typeColumnWidths =
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
    (~columnName: string, ~width: 'number_0, unit) => typeNextColumnWidths =
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
      ~onColumnWidthsChange: 'any_rzwa=?,
      ~minColumnWidth: 'number_t=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
      ~emptyMessageComponent: 'any_r10e=?,
      ~onHiddenColumnNamesChange: 'any_rke2=?,
      ~messages: 'any_recw=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~columnTogglingEnabled: bool=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
      ~cellComponent: 'any_ryvh=?,
      ~headerCellComponent: 'any_rf9g=?,
      ~commandComponent: 'any_r6jc=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_r4k6=?,
      ~messages: 'any_ry1s=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_r66s,
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
                   "getCellValue": ('any_rcl4, string) => 'any_rqjq,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r2ju,
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
                 "row": 'any_re4i,
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
                   "getCellValue": ('any_r1mo, string) => 'any_rs2m,
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
      ~rowHeight: 'number_c=?,
      ~cellComponent: 'any_rkyz=?,
      ~rowComponent: 'any_ricy=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_rg3h,
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
                   "getCellValue": ('any_rzu9, string) => 'any_rc37,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rcoa,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rvbv, string) => 'any_r24c,
               },
               "value": 'any_r588,
               "editingEnabled": bool,
               "onValueChange": 'any_r6i9 => unit,
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
                 "row": 'any_rlvv,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rgkb,
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
      ~rowHeight: 'number_u=?,
      ~messages: 'any_rzth=?,
      ~cellComponent: 'any_r08n=?,
      ~rowComponent: 'any_rx4j=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_rxwl,
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
                   "getCellValue": ('any_rrzn, string) => 'any_r5al,
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
                 "getCellValue": ('any_rwkz, string) => 'any_ry3o,
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
      ~cellComponent: 'any_rvvm=?,
      ~rowComponent: 'any_r1hu=?,
      ~indentCellComponent: 'any_rrb3=?,
      ~indentColumnWidth: 'number_0=?,
      ~showColumnsWhenGrouped: bool=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_ry7i,
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
                   "getCellValue": ('any_rysv, string) => 'any_r48b,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rzgf,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rsxw, string) => 'any_rulh,
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
                 "row": 'any_raav,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_ryit,
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
                 "row": 'any_r5ta,
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
                   "getCellValue": ('any_rpfz, string) => 'any_r8cx,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_rnk5,
               },
               "column": 'any_roiy,
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
      ~cellComponent: 'any_rnyg=?,
      ~rowComponent: 'any_rze7=?,
      ~messages: 'any_rfup=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_r5ja,
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
                   "getCellValue": ('any_rp7r, string) => 'any_rfux,
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
                 "getCellValue": ('any_ri82, string) => 'any_r0qx,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_r6ak) | `Enum(direction_enum)],
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

module TableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~columns: array('any_rll4),
      ~minColumnWidth: 'number_u,
      ~layoutComponent: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableLayout";
  let make =
      (
        ~columns: array('any_rll4),
        ~minColumnWidth: [ | `Int(int) | `Float(float)],
        ~layoutComponent: 'genericCallback,
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
  type align = [
    | [@bs.as "left"] `Left
    | [@bs.as "right"] `Right
    | [@bs.as "center"] `Center
  ];
  [@bs.obj]
  external makeProps :
    (
      ~contentComponent: 'any_ry0t=?,
      ~toggleCellComponent: 'any_rvla=?,
      ~cellComponent: 'any_rkkx=?,
      ~rowComponent: 'any_r8m5=?,
      ~toggleColumnWidth: 'number_9=?,
      ~rowHeight: 'number_k=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rn3d} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ro4n,
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
                   "getCellValue": ('any_re8q, string) => 'any_r5u4,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r8xx,
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
                 "row": 'any_r95s,
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
                   "getCellValue": ('any_rypj, string) => 'any_rd1x,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r3bi,
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
                 "row": 'any_r6n3,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rx67,
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
      ~headerCellComponent: 'any_r072=?,
      ~cellComponent: 'any_rs7k=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_e=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_rznf,
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
                   "getCellValue": ('any_rvij, string) => 'any_r5i1,
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
                 "row": 'any_ra46,
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
                   "getCellValue": ('any_rkqc, string) => 'any_rk48,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rbmg,
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
      ~cellComponent: 'any_rr6n=?,
      ~indentComponent: 'any_r8fv=?,
      ~expandButtonComponent: 'any_rjmu=?,
      ~checkboxComponent: 'any_r3vt=?,
      ~contentComponent: 'any_rfsq=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_robw,
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
                   "getCellValue": ('any_r956, string) => 'any_rzvb,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rh97,
               "row": 'any_rij1,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rzrs, string) => 'any_r7ba,
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
      ~width: 'number_5=?,
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
      ~cellComponent: 'any_r7ab=?,
      ~rowComponent: 'any_rl7k=?,
      ~noDataCellComponent: 'any_rfc1=?,
      ~noDataRowComponent: 'any_r349=?,
      ~stubRowComponent: 'any_r7or=?,
      ~stubCellComponent: 'any_rvrq=?,
      ~stubHeaderCellComponent: 'any_r4n9=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~messages: 'any_rxpa=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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
                 "row": 'any_rjby,
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
                   "getCellValue": ('any_rbwl, string) => 'any_rhru,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_r6nx,
               "row": 'any_r963,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_r6vo, string) => 'any_rriz,
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
                 "row": 'any_rj6j,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rd3p,
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
                 "row": 'any_rlz3,
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
                   "getCellValue": ('any_r7ji, string) => 'any_r6d2,
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
                 "row": 'any_r9id,
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
                 "row": 'any_rcfm,
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
                 "row": 'any_r1bd,
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
                   "getCellValue": ('any_rtpq, string) => 'any_rcbk,
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
                 "row": 'any_ryss,
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
                   "getCellValue": ('any_rv7m, string) => 'any_rep6,
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
      ~rootComponent: 'any_r0v9=?,
      ~flexibleSpaceComponent: 'genericCallback=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
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

module TreeDataState = {
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
      ~onExpandedRowIdsChange: 'any_ry1l=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TreeDataState";
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
          ~expandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              expandedRowIds,
            ),
          ~defaultExpandedRowIds=?
            Js.Option.map(
              (. v) =>
                Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v),
              defaultExpandedRowIds,
            ),
          ~onExpandedRowIdsChange?,
          (),
        ),
      children,
    );
};

module VirtualTableLayout = {
  [@bs.obj]
  external makeProps :
    (
      ~minWidth: 'number_v,
      ~minColumnWidth: 'number_v,
      ~height: 'number_z,
      ~headerRows: array('any_r665)=?,
      ~bodyRows: array('any_rgkt),
      ~columns: array('any_rr70),
      ~cellComponent: 'genericCallback,
      ~rowComponent: 'genericCallback,
      ~bodyComponent: 'genericCallback,
      ~headComponent: 'genericCallback=?,
      ~tableComponent: 'genericCallback,
      ~headTableComponent: 'genericCallback=?,
      ~containerComponent: 'genericCallback,
      ~estimatedRowHeight: 'number_7,
      ~getCellColSpan: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "VirtualTableLayout";
  let make =
      (
        ~minWidth: [ | `Int(int) | `Float(float)],
        ~minColumnWidth: [ | `Int(int) | `Float(float)],
        ~height: [ | `Int(int) | `Float(float)],
        ~headerRows: option(array('any_r665))=?,
        ~bodyRows: array('any_rgkt),
        ~columns: array('any_rr70),
        ~cellComponent: 'genericCallback,
        ~rowComponent: 'genericCallback,
        ~bodyComponent: 'genericCallback,
        ~headComponent: option('genericCallback)=?,
        ~tableComponent: 'genericCallback,
        ~headTableComponent: option('genericCallback)=?,
        ~containerComponent: 'genericCallback,
        ~estimatedRowHeight: [ | `Int(int) | `Float(float)],
        ~getCellColSpan: 'genericCallback,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~minWidth=unwrapValue(minWidth),
          ~minColumnWidth=unwrapValue(minColumnWidth),
          ~height=unwrapValue(height),
          ~headerRows?,
          ~bodyRows,
          ~columns,
          ~cellComponent,
          ~rowComponent,
          ~bodyComponent,
          ~headComponent?,
          ~tableComponent,
          ~headTableComponent?,
          ~containerComponent,
          ~estimatedRowHeight=unwrapValue(estimatedRowHeight),
          ~getCellColSpan,
          (),
        ),
      children,
    );
};
