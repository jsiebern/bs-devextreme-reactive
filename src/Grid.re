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
      ~overlayComponent: 'any_rd0n=?,
      ~containerComponent: 'any_rnwt=?,
      ~itemComponent: 'any_rirq=?,
      ~toggleButtonComponent: 'any_rb8p=?,
      ~messages: 'any_rxul=?,
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
               "target": 'any_reyu,
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
                   "getCellValue": ('any_r5uf, string) => 'any_rtnr,
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
               "buttonRef": 'any_rxun => unit,
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
      ~getChildGroups: 'any_r5oj,
      ~grouping: array(typeGrouping)=?,
      ~expandedGroups: 'invalidArrayType_rh2n=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomGrouping";
  let make =
      (
        ~getChildGroups:
           (array('any_r9qm), {. "columnName": string}, array('any_r9x4)) =>
           array(array('any_rpvv)),
        ~grouping: option(array(typeGrouping))=?,
        ~expandedGroups: option('invalidArrayType_rh2n)=?,
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
  [@bs.obj] external makeProps : (~totalCount: 'number_m=?, unit) => _ = "";
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
  [@bs.obj] external makeProps : (~getChildRows: 'any_r8rw, unit) => _ = "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "CustomTreeData";
  let make =
      (
        ~getChildRows:
           ([ | `Any('any_rfpu) | `Any('any_rsou)], array('any_rkoi)) =>
           array('any_r4wq),
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
      ~formatterComponent: 'any_rw55=?,
      ~editorComponent: 'any_rt6i=?,
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
                 "getCellValue": ('any_rxpx, string) => 'any_riei,
               },
               "row": 'any_ru3g,
               "value": 'any_rcrf,
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
                 "getCellValue": ('any_rw71, string) => 'any_r2mv,
               },
               "row": 'any_reyr,
               "value": 'any_rwa4,
               "onValueChange": 'any_rfm2 => unit,
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
    (~containerComponent: 'any_rwcg=?, ~columnComponent: 'any_ri1g=?, unit) =>
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
                 "getCellValue": ('any_rhtv, string) => 'any_rxs8,
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
      ~createRowChange: 'any_rn0v=?,
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
      ~added: array('any_r38n)=?,
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
      ~createRowChange: 'any_ref8=?,
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
      ~onEditingRowIdsChange: 'any_rshi=?,
      ~addedRows: array('any_rx59)=?,
      ~defaultAddedRows: array('any_r75y)=?,
      ~onAddedRowsChange: 'any_revw=?,
      ~rowChanges: Js.t({..})=?,
      ~defaultRowChanges: Js.t({..})=?,
      ~onRowChangesChange: 'any_r4vi=?,
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
      ~onDeletedRowIdsChange: 'any_r84l=?,
      ~onCommitChanges: 'any_rec2,
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
               'any_rmfh,
               string,
               [ | `String(string) | `Int(int) | `Float(float)]
             ) =>
             'any_ryib,
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
        ~addedRows: option(array('any_rx59))=?,
        ~defaultAddedRows: option(array('any_r75y))=?,
        ~onAddedRowsChange: option(array('any_rz1w) => unit)=?,
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
      ~onFiltersChange: 'any_rn9t=?,
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
    (~name: string, ~title: string=?, ~getCellValue: 'any_ruzt=?, unit) =>
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
      ~rows: array('any_rbvp)=?,
      ~getRowId: 'any_repq=?,
      ~getCellValue: 'any_r832=?,
      ~columns: array(typeColumns)=?,
      ~rootComponent: 'any_rbvx=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "Grid";
  let make =
      (
        ~rows: option(array('any_rbvp))=?,
        ~getRowId:
           option(
             'any_r7x7 => [ | `Int(int) | `Float(float) | `String(string)],
           )=?,
        ~getCellValue: option(('any_rdt1, string) => 'any_rhsz)=?,
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
      ~containerComponent: 'any_rj3f=?,
      ~itemComponent: 'any_rmmd=?,
      ~emptyMessageComponent: 'any_r6vu=?,
      ~messages: 'any_r7gj=?,
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
                   "getCellValue": ('any_rml2, string) => 'any_rol8,
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
                   "direction": [ | `Any('any_rld4) | `Enum(direction_enum)],
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
      ~onGroupingChange: 'any_rj9q=?,
      ~expandedGroups: 'invalidArrayType_rn41=?,
      ~defaultExpandedGroups: 'invalidArrayType_r5xt=?,
      ~onExpandedGroupsChange: 'any_rw96=?,
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
        ~expandedGroups: option('invalidArrayType_rn41)=?,
        ~defaultExpandedGroups: option('invalidArrayType_r5xt)=?,
        ~onExpandedGroupsChange: option('invalidArrayType_rcmd => unit)=?,
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
    (~columnName: string, ~predicate: 'any_r7lw=?, unit) =>
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
    (~key: 'union_r3rx, ~value: 'any_rt2f=?, unit) => typeCriteriaReturn =
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
    (~columnName: string, ~criteria: 'any_rprx=?, unit) => typeColumnExtensions =
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
    (~columnName: string, ~compare: 'any_r6fc=?, unit) => typeColumnExtensions =
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
    (~showAll: string=?, ~rowsPerPage: string=?, ~info: 'any_rc50=?, unit) =>
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
      ~pageSizes: 'arrayOf_rnho=?,
      ~containerComponent: 'any_r0js=?,
      ~messages: 'any_r6b8=?,
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
      ~pageSize: 'number_4=?,
      ~defaultPageSize: 'number_c=?,
      ~onPageSizeChange: 'any_rzrc=?,
      ~currentPage: 'number_r=?,
      ~defaultCurrentPage: 'number_i=?,
      ~onCurrentPageChange: 'any_ro5t=?,
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
      ~onExpandedRowIdsChange: 'any_rva6=?,
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
    (~inputComponent: 'any_riu5=?, ~messages: 'any_r6d5=?, unit) => _ =
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
      ~onValueChange: 'any_rpkr=?,
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
      ~onSelectionChange: 'any_r3f1=?,
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
    (~columnName: string, ~direction: string, unit) => typeSorting =
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
    (~columnName: string, ~direction: string, unit) => typeDefaultSorting =
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
      ~onSortingChange: 'any_rsm2=?,
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
      ~headerRows: array('any_rmk4)=?,
      ~bodyRows: array('any_rvqe),
      ~columns: array('any_r8ju),
      ~minWidth: 'number_6,
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
        ~headerRows: option(array('any_rmk4))=?,
        ~bodyRows: array('any_rvqe),
        ~columns: array('any_r8ju),
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
      ~columnBands: array('any_rrlg)=?,
      ~cellComponent: 'any_rg7x=?,
      ~rowComponent: 'any_r97p=?,
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
        ~columnBands: option(array('any_rrlg))=?,
        ~cellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_ri9r,
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
                   "getCellValue": ('any_r8a1, string) => 'any_rmw9,
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
      ~onOrderChange: 'any_rmlu=?,
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
    (~columnName: string, ~width: 'number_j, unit) => typeDefaultColumnWidths =
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
    (~columnName: string, ~width: 'number_o, unit) => typeColumnWidths =
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
    (~columnName: string, ~width: 'number_k, unit) => typeNextColumnWidths =
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
      ~onColumnWidthsChange: 'any_rg9n=?,
      ~minColumnWidth: 'number_m=?,
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
      ~emptyMessageComponent: 'any_rp23=?,
      ~onHiddenColumnNamesChange: 'any_r7uz=?,
      ~messages: 'any_rxjq=?,
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
      ~cellComponent: 'any_r4q1=?,
      ~headerCellComponent: 'any_rp4u=?,
      ~commandComponent: 'any_rv19=?,
      ~showAddCommand: bool=?,
      ~showEditCommand: bool=?,
      ~showDeleteCommand: bool=?,
      ~width: 'union_rilh=?,
      ~messages: 'any_rrxs=?,
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
                 "row": 'any_rbdr,
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
                   "getCellValue": ('any_rxjt, string) => 'any_r4ki,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_r6ps,
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
                 "row": 'any_r1m7,
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
                   "getCellValue": ('any_rml6, string) => 'any_rszd,
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
      ~rowHeight: 'number_k=?,
      ~cellComponent: 'any_rshv=?,
      ~rowComponent: 'any_r892=?,
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
                 "row": 'any_r76j,
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
                   "getCellValue": ('any_rueo, string) => 'any_rzsr,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rz3d,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rngq, string) => 'any_ry0c,
               },
               "value": 'any_ritq,
               "editingEnabled": bool,
               "onValueChange": 'any_r8m2 => unit,
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
                 "row": 'any_rail,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_r3s6,
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
      ~messages: 'any_rl2t=?,
      ~cellComponent: 'any_rlxy=?,
      ~rowComponent: 'any_rvxt=?,
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
                 "row": 'any_rpib,
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
                   "getCellValue": ('any_ruyb, string) => 'any_r10g,
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
                 "getCellValue": ('any_rxo2, string) => 'any_rq3l,
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
      ~cellComponent: 'any_rmgq=?,
      ~rowComponent: 'any_rbb0=?,
      ~indentCellComponent: 'any_rp7w=?,
      ~indentColumnWidth: 'number_m=?,
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
                 "row": 'any_rijv,
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
                   "getCellValue": ('any_rh34, string) => 'any_rrj1,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r4fr,
               },
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rasp, string) => 'any_rbxz,
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
                 "row": 'any_rwbo,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_reyj,
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
                 "row": 'any_ravh,
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
                   "getCellValue": ('any_ri84, string) => 'any_rtyw,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": {
                 .
                 "key": [ | `Int(int) | `Float(float) | `String(string)],
                 "value": 'any_r2uv,
               },
               "column": 'any_rdw0,
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
      ~cellComponent: 'any_rfdw=?,
      ~rowComponent: 'any_rdpo=?,
      ~messages: 'any_ru4e=?,
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
                 "row": 'any_rf3o,
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
                   "getCellValue": ('any_r7fx, string) => 'any_ruxk,
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
                 "getCellValue": ('any_ryo2, string) => 'any_rtib,
               },
               "showSortingControls": bool,
               "sortingEnabled": bool,
               "sortingDirection": sortingDirection,
               "onSort":
                 {
                   .
                   "direction": [ | `Any('any_rbgy) | `Enum(direction_enum)],
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
      ~columns: array('any_rmk4),
      ~minColumnWidth: 'number_o,
      ~layoutComponent: 'genericCallback,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableLayout";
  let make =
      (
        ~columns: array('any_rmk4),
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
      ~contentComponent: 'any_r1fr=?,
      ~toggleCellComponent: 'any_rv60=?,
      ~cellComponent: 'any_rgm5=?,
      ~rowComponent: 'any_r8ci=?,
      ~toggleColumnWidth: 'number_h=?,
      ~rowHeight: 'number_5=?,
      unit
    ) =>
    _ =
    "";
  [@bs.module "@devexpress/dx-react-grid"]
  external reactClass : ReasonReact.reactClass = "TableRowDetail";
  let make =
      (
        ~contentComponent:
           option({. "row": 'any_rrhm} => ReasonReact.reactElement)=?,
        ~toggleCellComponent:
           option(
             {
               .
               "tableRow": {
                 .
                 "key": string,
                 "type": string,
                 "rowId": [ | `Int(int) | `Float(float) | `String(string)],
                 "row": 'any_r4j7,
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
                   "getCellValue": ('any_rien, string) => 'any_rz6e,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_reof,
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
                 "row": 'any_rbmf,
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
                   "getCellValue": ('any_rqih, string) => 'any_rfgs,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rp1s,
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
                 "row": 'any_rj8s,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_rx27,
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
      ~headerCellComponent: 'any_r2to=?,
      ~cellComponent: 'any_rsv6=?,
      ~rowComponent: 'genericCallback=?,
      ~highlightRow: bool=?,
      ~selectByRowClick: bool=?,
      ~showSelectAll: bool=?,
      ~showSelectionColumn: bool=?,
      ~selectionColumnWidth: 'number_s=?,
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
                 "row": 'any_rovx,
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
                   "getCellValue": ('any_r0fb, string) => 'any_rqap,
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
                 "row": 'any_rdzp,
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
                   "getCellValue": ('any_ree4, string) => 'any_rcmf,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "row": 'any_rgv4,
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
      ~cellComponent: 'any_rvsi=?,
      ~indentComponent: 'any_r8b3=?,
      ~expandButtonComponent: 'any_raf0=?,
      ~checkboxComponent: 'any_rxbf=?,
      ~contentComponent: 'any_rdt3=?,
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
                 "row": 'any_rpnt,
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
                   "getCellValue": ('any_raie, string) => 'any_rrw8,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rn0h,
               "row": 'any_ry0y,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rsxu, string) => 'any_rwds,
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
      ~width: 'number_0=?,
      ~align: string=?,
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
      ~cellComponent: 'any_r8lr=?,
      ~rowComponent: 'any_rnnq=?,
      ~noDataCellComponent: 'any_r2ks=?,
      ~noDataRowComponent: 'any_rjte=?,
      ~stubRowComponent: 'any_rjie=?,
      ~stubCellComponent: 'any_reex=?,
      ~stubHeaderCellComponent: 'any_rojy=?,
      ~columnExtensions: array(typeColumnExtensions)=?,
      ~messages: 'any_rtrp=?,
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
                 "row": 'any_r7fp,
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
                   "getCellValue": ('any_r31s, string) => 'any_r2jx,
                 },
                 "width": [ | `Int(int) | `Float(float)],
                 "align": align,
               },
               "colSpan": [ | `Int(int) | `Float(float)],
               "rowSpan": [ | `Int(int) | `Float(float)],
               "value": 'any_rbzx,
               "row": 'any_rrww,
               "column": {
                 .
                 "name": string,
                 "title": string,
                 "getCellValue": ('any_rlu0, string) => 'any_r531,
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
                 "row": 'any_r0ue,
                 "height": [ | `Int(int) | `Float(float)],
               },
               "children": ReasonReact.reactElement,
               "row": 'any_r69f,
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
                 "row": 'any_rpxx,
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
                   "getCellValue": ('any_r3t7, string) => 'any_r1h0,
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
                 "row": 'any_reyz,
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
                 "row": 'any_rvgo,
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
                 "row": 'any_ry9a,
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
                   "getCellValue": ('any_rwv4, string) => 'any_rsz6,
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
                 "row": 'any_rqxg,
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
                   "getCellValue": ('any_rc17, string) => 'any_rbt3,
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
      ~rootComponent: 'any_r0og=?,
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
      ~onExpandedRowIdsChange: 'any_r4oz=?,
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
      ~minWidth: 'number_o,
      ~minColumnWidth: 'number_8,
      ~height: 'number_e,
      ~headerRows: array('any_rx2k)=?,
      ~bodyRows: array('any_r4ou),
      ~columns: array('any_r1o4),
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
        ~headerRows: option(array('any_rx2k))=?,
        ~bodyRows: array('any_r4ou),
        ~columns: array('any_r1o4),
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
