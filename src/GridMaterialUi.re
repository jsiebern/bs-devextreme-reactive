
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
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                showColumnChooser: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> showColumnChooserGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "showColumnChooser",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~overlayComponent: 'any_rh0w=?,
~containerComponent: 'any_r2ko=?,
~itemComponent: 'any_rq8v=?,
~toggleButtonComponent: 'any_r3e8=?,
~messages: 'any_rrfj=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "ColumnChooser";
                let make = (
                    ~overlayComponent: option(({.
                    "visible": bool,"target": 'any_r3uk,"onHide": unit => unit,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~containerComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(({.
                    "item": {.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_rozp, string) => 'any_rpqd
                },"hidden": bool
                },"disabled": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~toggleButtonComponent: option(({.
                    "onToggle": unit => unit,"getMessage": (string) => string,"buttonRef": ('any_rgp0) => unit
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~overlayComponent=?overlayComponent,
~containerComponent=?containerComponent,
~itemComponent=?itemComponent,
~toggleButtonComponent=?toggleButtonComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module DragDropProvider = {
                
                [@bs.obj] external makeProps : (~containerComponent: 'any_r6ln=?,
~columnComponent: 'any_rnjh=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "DragDropProvider";
                let make = (
                    ~containerComponent: option(({.
                    "clientOffset": {.
                    "x": [ | `Int(int) | `Float(float) ],"y": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~columnComponent: option(({.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_r0gn, string) => 'any_rzde
                }
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~containerComponent=?containerComponent,
~columnComponent=?columnComponent, ()),
                        children
                    );
            };
        

            module Grid = {
                

                    module Columns {
                        [@bs.deriving abstract]
                        type t('any_rlvu,'any_rg65) = {
                            
                                
                                
                                name: string
                            ,
                                [@bs.optional]
                                
                                title: string
                            ,
                                [@bs.optional]
                                
                                getCellValue: ('any_rlvu, string) => 'any_rg65
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_rlvu,'any_rg65)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "name",
                                            obj -> nameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> titleGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "title",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj -> getCellValueGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "getCellValue",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~rows: array('any_rxnq)=?,
~getRowId: 'any_r05n=?,
~getCellValue: 'any_ru2f=?,
~columns: array(Columns.t('any_rlvu,'any_rg65))=?,
~rootComponent: 'any_rdh1=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "Grid";
                let make = (
                    ~rows: option(array('any_rxnq))=?,
~getRowId: option(('any_rb95) => [ | `Int(int) | `Float(float) | `String(string)  ])=?,
~getCellValue: option(('any_rg7j, string) => 'any_rxab)=?,
~columns: option(array(Columns.t('any_rlvu,'any_rg65)))=?,
~rootComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rows=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), rows),
~getRowId=?getRowId,
~getCellValue=?getCellValue,
~columns=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(Columns.unwrap(item)), v)), columns),
~rootComponent=?rootComponent, ()),
                        children
                    );
            };
        

            module GroupingPanel = {
                

                [@bs.deriving jsConverter]
                type sortingDirection = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                [@bs.deriving jsConverter]
                type direction_enum = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                groupByColumn: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> groupByColumnGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "groupByColumn",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~showSortingControls: bool=?,
~showGroupingControls: bool=?,
~layoutComponent: 'genericCallback=?,
~containerComponent: 'any_rthb=?,
~itemComponent: 'any_raez=?,
~emptyMessageComponent: 'any_rtkj=?,
~messages: 'any_rkdr=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "GroupingPanel";
                let make = (
                    ~showSortingControls: option(bool)=?,
~showGroupingControls: option(bool)=?,
~layoutComponent: option('genericCallback)=?,
~containerComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(({.
                    "item": {.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_rcb1, string) => 'any_r788
                },"draft": string
                },"showGroupingControls": bool,"showSortingControls": bool,"groupingEnabled": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_r8go) | `Enum(direction_enum)  ]
                }) => unit,"onGroup": unit => unit
                }) => ReasonReact.reactElement)=?,
~emptyMessageComponent: option(({.
                    "getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~showSortingControls=?showSortingControls,
~showGroupingControls=?showGroupingControls,
~layoutComponent=?layoutComponent,
~containerComponent=?containerComponent,
~itemComponent=?itemComponent,
~emptyMessageComponent=?emptyMessageComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module PagingPanel = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                showAll: string
                            ,
                                [@bs.optional]
                                
                                rowsPerPage: string
                            ,
                                [@bs.optional]
                                
                                info: ({.
                    "from": [ | `Int(int) | `Float(float) ],"to": [ | `Int(int) | `Float(float) ],"count": [ | `Int(int) | `Float(float) ]
                }) => [ | `String(string) | `String(string)  ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> showAllGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "showAll",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> rowsPerPageGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "rowsPerPage",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> infoGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "info",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~pageSizes: 'arrayOf_rrv6=?,
~containerComponent: 'any_rak9=?,
~messages: 'any_r4k9=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "PagingPanel";
                let make = (
                    ~pageSizes: option([ | `IntArray(array(int))| `FloatArray(array(float)) ])=?,
~containerComponent: option(({.
                    "totalPages": [ | `Int(int) | `Float(float) ],"currentPage": [ | `Int(int) | `Float(float) ],"onCurrentPageChange": ([ | `Int(int) | `Float(float) ]) => unit,"pageSize": [ | `Int(int) | `Float(float) ],"onPageSizeChange": ([ | `Int(int) | `Float(float) ]) => unit,"pageSizes": [ | `IntArray(array(int))| `FloatArray(array(float)) ],"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~pageSizes=?Js.Option.map([@bs] ((v) => unwrapValue(v)), pageSizes),
~containerComponent=?containerComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module SearchPanel = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                searchPlaceholder: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> searchPlaceholderGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "searchPlaceholder",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~inputComponent: 'any_ruvx=?,
~messages: 'any_rt74=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "SearchPanel";
                let make = (
                    ~inputComponent: option(({.
                    "value": string,"onValueChange": (string) => unit,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~inputComponent=?inputComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableBandHeader = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~columnBands: array('any_rtd3)=?,
~cellComponent: 'any_rtik=?,
~rowComponent: 'any_rwdm=?,
~bandedHeaderCellComponent: 'genericCallback=?,
~invisibleCellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableBandHeader";
                let make = (
                    ~columnBands: option(array('any_rtd3))=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rg6v,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rni8, string) => 'any_rz3p
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~bandedHeaderCellComponent: option('genericCallback)=?,
~invisibleCellComponent: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~columnBands=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), columnBands),
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~bandedHeaderCellComponent=?bandedHeaderCellComponent,
~invisibleCellComponent=?invisibleCellComponent, ()),
                        children
                    );
            };
        

            module TableColumnReordering = {
                
                [@bs.obj] external makeProps : (~order: array(string)=?,
~defaultOrder: array(string)=?,
~onOrderChange: 'any_rgcr=?,
~tableContainerComponent: 'genericCallback=?,
~rowComponent: 'genericCallback=?,
~cellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableColumnReordering";
                let make = (
                    ~order: option(array(string))=?,
~defaultOrder: option(array(string))=?,
~onOrderChange: option((array(string)) => unit)=?,
~tableContainerComponent: option('genericCallback)=?,
~rowComponent: option('genericCallback)=?,
~cellComponent: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~order=?order,
~defaultOrder=?defaultOrder,
~onOrderChange=?onOrderChange,
~tableContainerComponent=?tableContainerComponent,
~rowComponent=?rowComponent,
~cellComponent=?cellComponent, ()),
                        children
                    );
            };
        

            module TableColumnResizing = {
                

                    module DefaultColumnWidths {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                width: [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "width",
                                            unwrapValue(obj -> widthGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module ColumnWidths {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                width: [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "width",
                                            unwrapValue(obj -> widthGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module NextColumnWidths {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                width: [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "width",
                                            unwrapValue(obj -> widthGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~defaultColumnWidths: array(DefaultColumnWidths.t)=?,
~columnWidths: array(ColumnWidths.t)=?,
~onColumnWidthsChange: 'any_rziw=?,
~minColumnWidth: 'number_9=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableColumnResizing";
                let make = (
                    ~defaultColumnWidths: option(array(DefaultColumnWidths.t))=?,
~columnWidths: option(array(ColumnWidths.t))=?,
~onColumnWidthsChange: option((array(NextColumnWidths.t)) => unit)=?,
~minColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~defaultColumnWidths=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(DefaultColumnWidths.unwrap(item)), v)), defaultColumnWidths),
~columnWidths=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnWidths.unwrap(item)), v)), columnWidths),
~onColumnWidthsChange=?onColumnWidthsChange,
~minColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), minColumnWidth), ()),
                        children
                    );
            };
        

            module TableColumnVisibility = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                noColumns: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> noColumnsGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "noColumns",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                togglingEnabled: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "togglingEnabled",
                                            obj -> togglingEnabledGet
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~hiddenColumnNames: array(string)=?,
~defaultHiddenColumnNames: array(string)=?,
~emptyMessageComponent: 'any_ri4z=?,
~onHiddenColumnNamesChange: 'any_riyp=?,
~messages: 'any_rgei=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~columnTogglingEnabled: bool=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableColumnVisibility";
                let make = (
                    ~hiddenColumnNames: option(array(string))=?,
~defaultHiddenColumnNames: option(array(string))=?,
~emptyMessageComponent: option(({.
                    "getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~onHiddenColumnNamesChange: option((array(string)) => unit)=?,
~messages: option(Messages.t)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
~columnTogglingEnabled: option(bool)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~hiddenColumnNames=?hiddenColumnNames,
~defaultHiddenColumnNames=?defaultHiddenColumnNames,
~emptyMessageComponent=?emptyMessageComponent,
~onHiddenColumnNamesChange=?onHiddenColumnNamesChange,
~messages=?Messages.unwrap(messages),
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~columnTogglingEnabled=?columnTogglingEnabled, ()),
                        children
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

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                addCommand: string
                            ,
                                [@bs.optional]
                                
                                editCommand: string
                            ,
                                [@bs.optional]
                                
                                deleteCommand: string
                            ,
                                [@bs.optional]
                                
                                commitCommand: string
                            ,
                                [@bs.optional]
                                
                                cancelCommand: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> addCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "addCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> editCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "editCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> deleteCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "deleteCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> commitCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "commitCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> cancelCommandGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "cancelCommand",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_r5tq=?,
~headerCellComponent: 'any_rzol=?,
~commandComponent: 'any_rqms=?,
~showAddCommand: bool=?,
~showEditCommand: bool=?,
~showDeleteCommand: bool=?,
~width: 'union_r3yu=?,
~messages: 'any_r2zy=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableEditColumn";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rup9,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rmjs, string) => 'any_ry7x
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_rleu,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r43g,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r7dy, string) => 'any_rhp7
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~commandComponent: option(({.
                    "id": id,"text": string,"onExecute": unit => unit
                }) => ReasonReact.reactElement)=?,
~showAddCommand: option(bool)=?,
~showEditCommand: option(bool)=?,
~showDeleteCommand: option(bool)=?,
~width: option([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~cellComponent=?cellComponent,
~headerCellComponent=?headerCellComponent,
~commandComponent=?commandComponent,
~showAddCommand=?showAddCommand,
~showEditCommand=?showEditCommand,
~showDeleteCommand=?showDeleteCommand,
~width=?Js.Option.map([@bs] (v => unwrapValue(v)), width),
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableEditRow = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~rowHeight: 'number_v=?,
~cellComponent: 'any_r67s=?,
~rowComponent: 'any_rhf2=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableEditRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rpb9,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r1te, string) => 'any_roep
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_rtg7,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r5zf, string) => 'any_rvs7
                },"value": 'any_relv,"editingEnabled": bool,"onValueChange": ('any_rpn6) => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rzcl,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_r12f
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowHeight),
~cellComponent=?cellComponent,
~rowComponent=?rowComponent, ()),
                        children
                    );
            };
        

            module TableFilterRow = {
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                filterPlaceholder: string
                            ,
                                [@bs.optional]
                                
                                contains: string
                            ,
                                [@bs.optional]
                                
                                notContains: string
                            ,
                                [@bs.optional]
                                
                                startsWith: string
                            ,
                                [@bs.optional]
                                
                                endsWith: string
                            ,
                                [@bs.optional]
                                
                                equal: string
                            ,
                                [@bs.optional]
                                
                                notEqual: string
                            ,
                                [@bs.optional]
                                
                                greaterThan: string
                            ,
                                [@bs.optional]
                                
                                greaterThanOrEqual: string
                            ,
                                [@bs.optional]
                                
                                lessThan: string
                            ,
                                [@bs.optional]
                                
                                lessThanOrEqual: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> filterPlaceholderGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "filterPlaceholder",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> containsGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "contains",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> notContainsGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "notContains",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> startsWithGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "startsWith",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> endsWithGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "endsWith",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> equalGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "equal",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> notEqualGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "notEqual",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> greaterThanGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "greaterThan",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> greaterThanOrEqualGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "greaterThanOrEqual",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> lessThanGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "lessThan",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> lessThanOrEqualGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "lessThanOrEqual",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~rowHeight: 'number_g=?,
~showFilterSelector: bool=?,
~messages: 'any_rlit=?,
~cellComponent: 'any_ri4i=?,
~rowComponent: 'any_rdb3=?,
~filterSelectorComponent: 'any_rlpf=?,
~iconComponent: 'any_rj5u=?,
~editorComponent: 'any_r638=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableFilterRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~showFilterSelector: option(bool)=?,
~messages: option(Messages.t)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ric8,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rpiq, string) => 'any_rxxy
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"filter": {.
                    "columnName": string,"operation": Js.t({..}),"value": string
                },"onFilter": ({.
                    "columnName": string,"operation": Js.t({..}),"value": string
                }) => unit,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rctl, string) => 'any_rfvi
                },"filteringEnabled": bool,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~rowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~filterSelectorComponent: option(({.
                    "iconComponent": ({.
                    "type": string
                }) => ReasonReact.reactElement,"value": string,"availableValues": array(string),"onChange": (string) => unit,"disabled": bool,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~iconComponent: option(({.
                    "type": string
                }) => ReasonReact.reactElement)=?,
~editorComponent: option(({.
                    "value": 'any_r8hd,"disabled": bool,"onChange": (string) => unit,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowHeight),
~showFilterSelector=?showFilterSelector,
~messages=?Messages.unwrap(messages),
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~filterSelectorComponent=?filterSelectorComponent,
~iconComponent=?iconComponent,
~editorComponent=?editorComponent, ()),
                        children
                    );
            };
        

            module TableGroupRow = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                showWhenGrouped: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> showWhenGroupedGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "showWhenGrouped",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_rmz4=?,
~rowComponent: 'any_rwdw=?,
~indentCellComponent: 'any_rtoy=?,
~indentColumnWidth: 'number_l=?,
~showColumnsWhenGrouped: bool=?,
~columnExtensions: array(ColumnExtensions.t)=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableGroupRow";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rljn,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rstf, string) => 'any_rqe1
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_rrih
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r3gu, string) => 'any_rhqh
                },"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_regh,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_ref0
                }
                }) => ReasonReact.reactElement)=?,
~indentCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r7qo,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rqc6, string) => 'any_r613
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_rb6v
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r4s2, string) => 'any_ry22
                }
                }) => ReasonReact.reactElement)=?,
~indentColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
~showColumnsWhenGrouped: option(bool)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~indentCellComponent=?indentCellComponent,
~indentColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), indentColumnWidth),
~showColumnsWhenGrouped=?showColumnsWhenGrouped,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions), ()),
                        children
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
                type sortingDirection = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                [@bs.deriving jsConverter]
                type direction_enum = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                sortingHint: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> sortingHintGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "sortingHint",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~showSortingControls: bool=?,
~showGroupingControls: bool=?,
~cellComponent: 'any_rzq9=?,
~rowComponent: 'any_rby5=?,
~messages: 'any_rph9=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableHeaderRow";
                let make = (
                    ~showSortingControls: option(bool)=?,
~showGroupingControls: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rsp6,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rzxi, string) => 'any_rxty
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rdug, string) => 'any_retj
                },"showSortingControls": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_r0jy) | `Enum(direction_enum)  ],"keepOther": bool
                }) => unit,"showGroupingControls": bool,"groupingEnabled": bool,"onGroup": unit => unit,"resizingEnabled": bool,"onWidthChange": ({.
                    "shift": [ | `Int(int) | `Float(float) ]
                }) => unit,"onWidthDraft": ({.
                    "shift": [ | `Int(int) | `Float(float) ]
                }) => unit,"onWidthDraftCancel": unit => unit,"draggingEnabled": bool,"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~rowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~showSortingControls=?showSortingControls,
~showGroupingControls=?showGroupingControls,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableRowDetail = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~contentComponent: 'any_rhac=?,
~toggleCellComponent: 'any_rq7m=?,
~cellComponent: 'any_rz1r=?,
~rowComponent: 'any_rx1g=?,
~toggleColumnWidth: 'number_3=?,
~rowHeight: 'number_p=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableRowDetail";
                let make = (
                    ~contentComponent: option(({.
                    "row": 'any_r0z6
                }) => ReasonReact.reactElement)=?,
~toggleCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rbyx,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rlno, string) => 'any_rpk1
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r3cc,"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rduf,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rnpu, string) => 'any_rb9e
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r696,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rmby,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_r93g
                }) => ReasonReact.reactElement)=?,
~toggleColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~contentComponent=?contentComponent,
~toggleCellComponent=?toggleCellComponent,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~toggleColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), toggleColumnWidth),
~rowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowHeight), ()),
                        children
                    );
            };
        

            module TableSelection = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~headerCellComponent: 'any_rjsa=?,
~cellComponent: 'any_rgbz=?,
~rowComponent: 'genericCallback=?,
~highlightRow: bool=?,
~selectByRowClick: bool=?,
~showSelectAll: bool=?,
~showSelectionColumn: bool=?,
~selectionColumnWidth: 'number_4=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableSelection";
                let make = (
                    ~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rzq2,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r7fo, string) => 'any_rh39
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"disabled": bool,"allSelected": bool,"someSelected": bool,"onToggle": (bool) => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rilc,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r3p9, string) => 'any_rovb
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r8dj,"selected": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option('genericCallback)=?,
~highlightRow: option(bool)=?,
~selectByRowClick: option(bool)=?,
~showSelectAll: option(bool)=?,
~showSelectionColumn: option(bool)=?,
~selectionColumnWidth: option([ | `Int(int) | `Float(float) ])=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~headerCellComponent=?headerCellComponent,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~highlightRow=?highlightRow,
~selectByRowClick=?selectByRowClick,
~showSelectAll=?showSelectAll,
~showSelectionColumn=?showSelectionColumn,
~selectionColumnWidth=?Js.Option.map([@bs] ((v) => unwrapValue(v)), selectionColumnWidth), ()),
                        children
                    );
            };
        

            module TableSummaryRow = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                count: string
                            ,
                                [@bs.optional]
                                
                                sum: string
                            ,
                                [@bs.optional]
                                
                                min: string
                            ,
                                [@bs.optional]
                                
                                max: string
                            ,
                                [@bs.optional]
                                
                                avg: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> countGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "count",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> sumGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "sum",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> minGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "min",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> maxGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "max",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                            switch (obj -> avgGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "avg",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~formatlessSummaryTypes: array(string)=?,
~totalRowComponent: 'any_rk11=?,
~groupRowComponent: 'any_rpcs=?,
~treeRowComponent: 'any_r9im=?,
~totalCellComponent: 'any_rbb0=?,
~groupCellComponent: 'any_rkvb=?,
~treeCellComponent: 'any_ruly=?,
~treeColumnCellComponent: 'any_r3ze=?,
~treeColumnContentComponent: 'any_rwnc=?,
~treeColumnIndentComponent: 'any_ruab=?,
~itemComponent: ReasonReact.reactElement=?,
~messages: 'any_rfva=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableSummaryRow";
                let make = (
                    ~formatlessSummaryTypes: option(array(string))=?,
~totalRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~groupRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~treeRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~totalCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r8jo,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ro1a, string) => 'any_rtaw
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r77u, string) => 'any_reid
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~groupCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rbyp,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rwa2, string) => 'any_r365
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_raby, string) => 'any_rjq0
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rjqu,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rzaz, string) => 'any_rfh9
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_riay, string) => 'any_r61b
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_regm,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r6pt, string) => 'any_r8nt
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rnl0, string) => 'any_r4wp
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnContentComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnIndentComponent: option(({.
                    "level": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(ReasonReact.reactElement)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~formatlessSummaryTypes=?formatlessSummaryTypes,
~totalRowComponent=?totalRowComponent,
~groupRowComponent=?groupRowComponent,
~treeRowComponent=?treeRowComponent,
~totalCellComponent=?totalCellComponent,
~groupCellComponent=?groupCellComponent,
~treeCellComponent=?treeCellComponent,
~treeColumnCellComponent=?treeColumnCellComponent,
~treeColumnContentComponent=?treeColumnContentComponent,
~treeColumnIndentComponent=?treeColumnIndentComponent,
~itemComponent=?itemComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module TableTreeColumn = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];
                [@bs.obj] external makeProps : (~_for: string=?,
~showSelectionControls: bool=?,
~showSelectAll: bool=?,
~cellComponent: 'any_rtkh=?,
~indentComponent: 'any_rs28=?,
~expandButtonComponent: 'any_rs5t=?,
~checkboxComponent: 'any_r3vf=?,
~contentComponent: 'any_rxsv=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "TableTreeColumn";
                let make = (
                    ~for_: option(string)=?,
~showSelectionControls: option(bool)=?,
~showSelectAll: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r5f8,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rfka, string) => 'any_rsng
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_rrcl,"row": 'any_rcps,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r5r0, string) => 'any_r5zz
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~indentComponent: option(({.
                    "level": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~expandButtonComponent: option(({.
                    "visible": bool,"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~checkboxComponent: option(({.
                    "disabled": bool,"checked": bool,"indeterminate": bool,"onChange": unit => unit
                }) => ReasonReact.reactElement)=?,
~contentComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~_for=?for_,
~showSelectionControls=?showSelectionControls,
~showSelectAll=?showSelectAll,
~cellComponent=?cellComponent,
~indentComponent=?indentComponent,
~expandButtonComponent=?expandButtonComponent,
~checkboxComponent=?checkboxComponent,
~contentComponent=?contentComponent, ()),
                        children
                    );
            };
        

            module Table = {
                

                [@bs.deriving jsConverter]
                type align = [
                    | [@bs.as "left"] `Left
| [@bs.as "right"] `Right
| [@bs.as "center"] `Center
                ];

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                width: [ | `Int(int) | `Float(float) ]
                            ,
                                [@bs.optional]
                                
                                align: align
                            ,
                                [@bs.optional]
                                
                                wordWrapEnabled: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (Js.Option.map([@bs] ((v) => unwrapValue(v)), obj -> widthGet)) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "width",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (Js.Option.map([@bs] (v => alignToJs(v)), obj -> alignGet)) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "align",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj -> wordWrapEnabledGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "wordWrapEnabled",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                noData: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> noDataGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "noData",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~layoutComponent: 'genericCallback=?,
~tableComponent: ReasonReact.reactElement=?,
~headComponent: ReasonReact.reactElement=?,
~bodyComponent: ReasonReact.reactElement=?,
~footerComponent: ReasonReact.reactElement=?,
~containerComponent: ReasonReact.reactElement=?,
~cellComponent: 'any_rcc0=?,
~rowComponent: 'any_raje=?,
~noDataCellComponent: 'any_rbla=?,
~noDataRowComponent: 'any_rfes=?,
~stubRowComponent: 'any_ruii=?,
~stubCellComponent: 'any_rggq=?,
~stubHeaderCellComponent: 'any_rmiv=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~messages: 'any_rcm0=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "Table";
                let make = (
                    ~layoutComponent: option('genericCallback)=?,
~tableComponent: option(ReasonReact.reactElement)=?,
~headComponent: option(ReasonReact.reactElement)=?,
~bodyComponent: option(ReasonReact.reactElement)=?,
~footerComponent: option(ReasonReact.reactElement)=?,
~containerComponent: option(ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rate,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rety, string) => 'any_rnwi
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_rbqh,"row": 'any_rce5,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rszc, string) => 'any_ro4p
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rex0,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_rwqv
                }) => ReasonReact.reactElement)=?,
~noDataCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rp07,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ryt2, string) => 'any_rj0e
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~noDataRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rsbz,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r22y,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rvnl,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rkms, string) => 'any_rk9d
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~stubHeaderCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rzgu,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rm8g, string) => 'any_r8c7
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~layoutComponent=?layoutComponent,
~tableComponent=?tableComponent,
~headComponent=?headComponent,
~bodyComponent=?bodyComponent,
~footerComponent=?footerComponent,
~containerComponent=?containerComponent,
~cellComponent=?cellComponent,
~rowComponent=?rowComponent,
~noDataCellComponent=?noDataCellComponent,
~noDataRowComponent=?noDataRowComponent,
~stubRowComponent=?stubRowComponent,
~stubCellComponent=?stubCellComponent,
~stubHeaderCellComponent=?stubHeaderCellComponent,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        

            module Toolbar = {
                
                [@bs.obj] external makeProps : (~rootComponent: 'any_ru4y=?,
~flexibleSpaceComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "Toolbar";
                let make = (
                    ~rootComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~flexibleSpaceComponent: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~rootComponent=?rootComponent,
~flexibleSpaceComponent=?flexibleSpaceComponent, ()),
                        children
                    );
            };
        

            module VirtualTable = {
                

                [@bs.deriving jsConverter]
                type height_enum = [
                    | [@bs.as "auto"] `Auto
                ];

                    module Messages {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                noData: string
                            
                        };
                        let make = t;

                        let unwrap = (obj: option(t)) => {
                            
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        
                                            switch (obj -> noDataGet) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        -> Js.Dict.set(
                                                            "noData",
                                                            v
                                                            -> toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~estimatedRowHeight: 'number_8=?,
~height: 'union_rb69=?,
~headTableComponent: 'genericCallback=?,
~footerTableComponent: 'genericCallback=?,
~messages: 'any_r6nq=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid-material-ui"] external reactClass : ReasonReact.reactClass = "VirtualTable";
                let make = (
                    ~estimatedRowHeight: option([ | `Int(int) | `Float(float) ])=?,
~height: option([ | `Int(int) | `Float(float) | `Enum(height_enum)  ])=?,
~headTableComponent: option('genericCallback)=?,
~footerTableComponent: option('genericCallback)=?,
~messages: option(Messages.t)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~estimatedRowHeight=?Js.Option.map([@bs] ((v) => unwrapValue(v)), estimatedRowHeight),
~height=?
                    Js.Option.map([@bs] ((v) => switch v {
                        | `Enum(v) => unwrapValue(`String(height_enumToJs(v)))
                        
                        | v => unwrapValue(v)
                    }), height)
                ,
~headTableComponent=?headTableComponent,
~footerTableComponent=?footerTableComponent,
~messages=?Messages.unwrap(messages), ()),
                        children
                    );
            };
        