
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
                
                [@bs.obj] external makeProps : (~overlayComponent: 'any_ryw7=?,
~containerComponent: 'any_r2c6=?,
~itemComponent: 'any_r3pf=?,
~toggleButtonComponent: 'any_ryn1=?,
~messages: 'any_rdtx=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "ColumnChooser";
                let make = (
                    ~overlayComponent: option(({.
                    "visible": bool,"target": 'any_rsie,"onHide": unit => unit,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~containerComponent: option(({.
                    "children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~itemComponent: option(({.
                    "item": {.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_rqnx, string) => 'any_rmdb
                },"hidden": bool
                },"disabled": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~toggleButtonComponent: option(({.
                    "onToggle": unit => unit,"getMessage": (string) => string,"buttonRef": ('any_rj8a) => unit
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
        

            module CustomGrouping = {
                

                    module Grouping {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            
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
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~getChildGroups: 'any_rymk,
~grouping: array(Grouping.t)=?,
~expandedGroups: 'invalidArrayType_r1y2=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "CustomGrouping";
                let make = (
                    ~getChildGroups: (array('any_rfg1), {.
                    "columnName": string
                }, array('any_r4nj)) => array(array('any_r0rm)),
~grouping: option(array(Grouping.t))=?,
~expandedGroups: option('invalidArrayType_r1y2)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~getChildGroups=getChildGroups,
~grouping=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(Grouping.unwrap(item)), v)), grouping),
~expandedGroups=?expandedGroups, ()),
                        children
                    );
            };
        

            module CustomPaging = {
                
                [@bs.obj] external makeProps : (~totalCount: 'number_2=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "CustomPaging";
                let make = (
                    ~totalCount: option([ | `Int(int) | `Float(float) ])=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~totalCount=?Js.Option.map([@bs] ((v) => unwrapValue(v)), totalCount), ()),
                        children
                    );
            };
        

            module CustomSummary = {
                
                [@bs.obj] external makeProps : (~totalValues: array('any_rzj6)=?,
~groupValues: array('any_r3fz)=?,
~treeValues: array('any_r53y)=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "CustomSummary";
                let make = (
                    ~totalValues: option(array('any_rzj6))=?,
~groupValues: option(array('any_r3fz))=?,
~treeValues: option(array('any_r53y))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~totalValues=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), totalValues),
~groupValues=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), groupValues),
~treeValues=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), treeValues), ()),
                        children
                    );
            };
        

            module CustomTreeData = {
                
                [@bs.obj] external makeProps : (~getChildRows: 'any_rgw3, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "CustomTreeData";
                let make = (
                    ~getChildRows: ([ | `Any('any_rw7j) | `Any('any_rkhn)  ], array('any_recz)) => array('any_rrqs),
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~getChildRows=getChildRows, ()),
                        children
                    );
            };
        

            module DataTypeProvider = {
                
                [@bs.obj] external makeProps : (~_for: array(string),
~formatterComponent: 'any_rcvi=?,
~editorComponent: 'any_rsr3=?,
~availableFilterOperations: 'invalidArrayType_rput=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "DataTypeProvider";
                let make = (
                    ~for_: array(string),
~formatterComponent: option(({.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_r5e0, string) => 'any_r7xg
                },"row": 'any_r5yp,"value": 'any_rw7y
                }) => ReasonReact.reactElement)=?,
~editorComponent: option(({.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_ra4t, string) => 'any_rm0t
                },"row": 'any_rbfr,"value": 'any_rlnb,"onValueChange": ('any_rz7l) => unit
                }) => ReasonReact.reactElement)=?,
~availableFilterOperations: option('invalidArrayType_rput)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~_for=for_,
~formatterComponent=?formatterComponent,
~editorComponent=?editorComponent,
~availableFilterOperations=?availableFilterOperations, ()),
                        children
                    );
            };
        

            module DragDropProvider = {
                
                [@bs.obj] external makeProps : (~containerComponent: 'any_rw23=?,
~columnComponent: 'any_rl4f=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "DragDropProvider";
                let make = (
                    ~containerComponent: option(({.
                    "clientOffset": {.
                    "x": [ | `Int(int) | `Float(float) ],"y": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~columnComponent: option(({.
                    "column": {.
                    "name": string,"title": string,"getCellValue": ('any_rw5i, string) => 'any_r7fd
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
        

            module EditingState = {
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t('any_riju,'any_rcho,'any_rxdf) = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                editingEnabled: bool
                            ,
                                [@bs.optional]
                                
                                createRowChange: ('any_riju, 'any_rcho, string) => 'any_rxdf
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_riju,'any_rcho,'any_rxdf)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> editingEnabledGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "editingEnabled",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj -> createRowChangeGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "createRowChange",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~createRowChange: 'any_rlc0=?,
~columnEditingEnabled: bool=?,
~columnExtensions: array(ColumnExtensions.t('any_riju,'any_rcho,'any_rxdf))=?,
~editingRowIds: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~defaultEditingRowIds: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~onEditingRowIdsChange: 'any_rpd1=?,
~addedRows: array('any_r0hr)=?,
~defaultAddedRows: array('any_r9ax)=?,
~onAddedRowsChange: 'any_rv10=?,
~rowChanges: Js.t({..})=?,
~defaultRowChanges: Js.t({..})=?,
~onRowChangesChange: 'any_rthq=?,
~deletedRowIds: array('any_rsp7)=?,
~defaultDeletedRowIds: array('any_rpef)=?,
~onDeletedRowIdsChange: 'genericCallback=?,
~onCommitChanges: 'any_rd19, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "EditingState";
                let make = (
                    ~createRowChange: option(('any_rzje, string, [ | `String(string) | `Int(int) | `Float(float)  ]) => 'any_r1ep)=?,
~columnEditingEnabled: option(bool)=?,
~columnExtensions: option(array(ColumnExtensions.t('any_riju,'any_rcho,'any_rxdf)))=?,
~editingRowIds: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~defaultEditingRowIds: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~onEditingRowIdsChange: option((array([ | `Int(int) | `Float(float) | `String(string)  ])) => unit)=?,
~addedRows: option(array('any_r0hr))=?,
~defaultAddedRows: option(array('any_r9ax))=?,
~onAddedRowsChange: option((array('any_ru30)) => unit)=?,
~rowChanges: option(Js.t({..}))=?,
~defaultRowChanges: option(Js.t({..}))=?,
~onRowChangesChange: option((Js.t({..})) => unit)=?,
~deletedRowIds: option(array('any_rsp7))=?,
~defaultDeletedRowIds: option(array('any_rpef))=?,
~onDeletedRowIdsChange: option('genericCallback)=?,
~onCommitChanges: ({.
                    "added": array('any_rfgb),"changed": Js.t({..}),"deleted": array([ | `Int(int) | `Float(float) | `String(string)  ])
                }) => unit,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~createRowChange=?createRowChange,
~columnEditingEnabled=?columnEditingEnabled,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~editingRowIds=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), editingRowIds),
~defaultEditingRowIds=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), defaultEditingRowIds),
~onEditingRowIdsChange=?onEditingRowIdsChange,
~addedRows=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), addedRows),
~defaultAddedRows=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(item), v)), defaultAddedRows),
~onAddedRowsChange=?onAddedRowsChange,
~rowChanges=?rowChanges,
~defaultRowChanges=?defaultRowChanges,
~onRowChangesChange=?onRowChangesChange,
~deletedRowIds=?deletedRowIds,
~defaultDeletedRowIds=?defaultDeletedRowIds,
~onDeletedRowIdsChange=?onDeletedRowIdsChange,
~onCommitChanges=onCommitChanges, ()),
                        children
                    );
            };
        

            module FilteringState = {
                

                    module Filters {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                value: string
                            
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
                                
                                    switch (obj -> valueGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "value",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module DefaultFilters {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                value: string
                            
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
                                
                                    switch (obj -> valueGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "value",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                filteringEnabled: bool
                            
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
                                            "filteringEnabled",
                                            obj -> filteringEnabledGet
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~filters: array(Filters.t)=?,
~defaultFilters: array(DefaultFilters.t)=?,
~onFiltersChange: 'any_rsh3=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~columnFilteringEnabled: bool=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "FilteringState";
                let make = (
                    ~filters: option(array(Filters.t))=?,
~defaultFilters: option(array(DefaultFilters.t))=?,
~onFiltersChange: option((array(Filters.t)) => unit)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
~columnFilteringEnabled: option(bool)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~filters=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(Filters.unwrap(item)), v)), filters),
~defaultFilters=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(DefaultFilters.unwrap(item)), v)), defaultFilters),
~onFiltersChange=?onFiltersChange,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~columnFilteringEnabled=?columnFilteringEnabled, ()),
                        children
                    );
            };
        

            module Grid = {
                

                    module Columns {
                        [@bs.deriving abstract]
                        type t('any_rtfw,'any_rhhc) = {
                            
                                
                                
                                name: string
                            ,
                                [@bs.optional]
                                
                                title: string
                            ,
                                [@bs.optional]
                                
                                getCellValue: ('any_rtfw, string) => 'any_rhhc
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_rtfw,'any_rhhc)) => {
                            
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
                
                [@bs.obj] external makeProps : (~rows: array('any_r3r3)=?,
~getRowId: 'any_rdv2=?,
~getCellValue: 'any_ra0j=?,
~columns: array(Columns.t('any_rtfw,'any_rhhc))=?,
~rootComponent: 'any_rqpj=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "Grid";
                let make = (
                    ~rows: option(array('any_r3r3))=?,
~getRowId: option(('any_rj7g) => [ | `Int(int) | `Float(float) | `String(string)  ])=?,
~getCellValue: option(('any_rcvf, string) => 'any_ry1y)=?,
~columns: option(array(Columns.t('any_rtfw,'any_rhhc)))=?,
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
        

            module GroupPanelLayout = {
                

                    module Items {
                        [@bs.deriving abstract]
                        type t('a) = {
                            
                                [@bs.optional]
                                
                                column: Js.t({..}) as 'a
                            ,
                                [@bs.optional]
                                
                                draft: bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('a)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    switch (obj -> columnGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "column",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj -> draftGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "draft",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~items: array(Items.t('a)),
~onGroup: 'genericCallback=?,
~itemComponent: 'genericCallback,
~containerComponent: 'genericCallback,
~emptyMessageComponent: 'genericCallback,
~draggingEnabled: bool=?,
~isColumnGroupingEnabled: 'genericCallback=?,
~onGroupDraft: 'genericCallback=?,
~onGroupDraftCancel: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "GroupPanelLayout";
                let make = (
                    ~items: array(Items.t('a)),
~onGroup: option('genericCallback)=?,
~itemComponent: 'genericCallback,
~containerComponent: 'genericCallback,
~emptyMessageComponent: 'genericCallback,
~draggingEnabled: option(bool)=?,
~isColumnGroupingEnabled: option('genericCallback)=?,
~onGroupDraft: option('genericCallback)=?,
~onGroupDraftCancel: option('genericCallback)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~items=Js.Array.map(item => toJsUnsafe(Items.unwrap(item)), items),
~onGroup=?onGroup,
~itemComponent=itemComponent,
~containerComponent=containerComponent,
~emptyMessageComponent=emptyMessageComponent,
~draggingEnabled=?draggingEnabled,
~isColumnGroupingEnabled=?isColumnGroupingEnabled,
~onGroupDraft=?onGroupDraft,
~onGroupDraftCancel=?onGroupDraftCancel, ()),
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
~containerComponent: 'any_rkkr=?,
~itemComponent: 'any_r373=?,
~emptyMessageComponent: 'any_rfm1=?,
~messages: 'any_rnxf=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "GroupingPanel";
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
                    "name": string,"title": string,"getCellValue": ('any_rwhl, string) => 'any_r0fh
                },"draft": string
                },"showGroupingControls": bool,"showSortingControls": bool,"groupingEnabled": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_rbgi) | `Enum(direction_enum)  ]
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
        

            module GroupingState = {
                

                    module Grouping {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            
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
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module DefaultGrouping {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            
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
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                groupingEnabled: bool
                            
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
                                            "groupingEnabled",
                                            obj -> groupingEnabledGet
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~grouping: array(Grouping.t)=?,
~defaultGrouping: array(DefaultGrouping.t)=?,
~onGroupingChange: 'any_ruhq=?,
~expandedGroups: 'invalidArrayType_ryve=?,
~defaultExpandedGroups: 'invalidArrayType_r4zo=?,
~onExpandedGroupsChange: 'any_rcj1=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~columnGroupingEnabled: bool=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "GroupingState";
                let make = (
                    ~grouping: option(array(Grouping.t))=?,
~defaultGrouping: option(array(DefaultGrouping.t))=?,
~onGroupingChange: option((array(Grouping.t)) => unit)=?,
~expandedGroups: option('invalidArrayType_ryve)=?,
~defaultExpandedGroups: option('invalidArrayType_r4zo)=?,
~onExpandedGroupsChange: option(('invalidArrayType_rczf) => unit)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
~columnGroupingEnabled: option(bool)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~grouping=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(Grouping.unwrap(item)), v)), grouping),
~defaultGrouping=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(DefaultGrouping.unwrap(item)), v)), defaultGrouping),
~onGroupingChange=?onGroupingChange,
~expandedGroups=?expandedGroups,
~defaultExpandedGroups=?defaultExpandedGroups,
~onExpandedGroupsChange=?onExpandedGroupsChange,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~columnGroupingEnabled=?columnGroupingEnabled, ()),
                        children
                    );
            };
        

            module IntegratedFiltering = {
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t('any_r67a,'any_rs7o,'a) = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                predicate: ('any_r67a, {.
                    "columnName": string,"operation": Js.t({..}) as 'a,"value": string
                }, 'any_rs7o) => bool
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_r67a,'any_rs7o,'a)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> predicateGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "predicate",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~columnExtensions: array(ColumnExtensions.t('any_r67a,'any_rs7o,'a))=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "IntegratedFiltering";
                let make = (
                    ~columnExtensions: option(array(ColumnExtensions.t('any_r67a,'any_rs7o,'a)))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions), ()),
                        children
                    );
            };
        

            module IntegratedGrouping = {
                

                    module CriteriaReturn {
                        [@bs.deriving abstract]
                        type t('any_rwgt) = {
                            
                                
                                
                                key: [ | `String(string) | `Int(int) | `Float(float)  ]
                            ,
                                [@bs.optional]
                                
                                value: 'any_rwgt
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_rwgt)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "key",
                                            unwrapValue(obj -> keyGet)
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> valueGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "value",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t('any_r1cl,'any_rwgt) = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                criteria: ('any_r1cl) => CriteriaReturn.t('any_rwgt)
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_r1cl,'any_rwgt)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> criteriaGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "criteria",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~columnExtensions: array(ColumnExtensions.t('any_r1cl,'any_rwgt))=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "IntegratedGrouping";
                let make = (
                    ~columnExtensions: option(array(ColumnExtensions.t('any_r1cl,'any_rwgt)))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions), ()),
                        children
                    );
            };
        

            module IntegratedPaging = {
                
                
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "IntegratedPaging";
                let make = (
                    
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=Js.Obj.empty(),
                        children
                    );
            };
        

            module IntegratedSelection = {
                
                
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "IntegratedSelection";
                let make = (
                    
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=Js.Obj.empty(),
                        children
                    );
            };
        

            module IntegratedSorting = {
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t('any_r56p,'any_r0w9) = {
                            
                                
                                
                                columnName: string
                            ,
                                [@bs.optional]
                                
                                compare: ('any_r56p, 'any_r0w9) => [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t('any_r56p,'any_r0w9)) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    unwrappedMap
                                        -> Js.Dict.set(
                                            "columnName",
                                            obj -> columnNameGet
                                            -> toJsUnsafe
                                        );
                                
                                    switch (obj -> compareGet) {
                                        | Some(v) =>
                                            unwrappedMap
                                                -> Js.Dict.set(
                                                    "compare",
                                                    v
                                                    -> toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~columnExtensions: array(ColumnExtensions.t('any_r56p,'any_r0w9))=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "IntegratedSorting";
                let make = (
                    ~columnExtensions: option(array(ColumnExtensions.t('any_r56p,'any_r0w9)))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions), ()),
                        children
                    );
            };
        

            module IntegratedSummary = {
                
                [@bs.obj] external makeProps : (~calculator: 'any_rhjo=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "IntegratedSummary";
                let make = (
                    ~calculator: option((Js.t({..}), array('any_rgu5), ('any_rvgy) => 'any_r0jp) => 'any_r9ku)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~calculator=?calculator, ()),
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
                
                [@bs.obj] external makeProps : (~pageSizes: 'arrayOf_rrmi=?,
~containerComponent: 'any_rdd7=?,
~messages: 'any_rrgx=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "PagingPanel";
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
        

            module PagingState = {
                
                [@bs.obj] external makeProps : (~pageSize: 'number_d=?,
~defaultPageSize: 'number_y=?,
~onPageSizeChange: 'any_renm=?,
~currentPage: 'number_8=?,
~defaultCurrentPage: 'number_p=?,
~onCurrentPageChange: 'any_rhma=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "PagingState";
                let make = (
                    ~pageSize: option([ | `Int(int) | `Float(float) ])=?,
~defaultPageSize: option([ | `Int(int) | `Float(float) ])=?,
~onPageSizeChange: option(([ | `Int(int) | `Float(float) ]) => unit)=?,
~currentPage: option([ | `Int(int) | `Float(float) ])=?,
~defaultCurrentPage: option([ | `Int(int) | `Float(float) ])=?,
~onCurrentPageChange: option(([ | `Int(int) | `Float(float) ]) => unit)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~pageSize=?Js.Option.map([@bs] ((v) => unwrapValue(v)), pageSize),
~defaultPageSize=?Js.Option.map([@bs] ((v) => unwrapValue(v)), defaultPageSize),
~onPageSizeChange=?onPageSizeChange,
~currentPage=?Js.Option.map([@bs] ((v) => unwrapValue(v)), currentPage),
~defaultCurrentPage=?Js.Option.map([@bs] ((v) => unwrapValue(v)), defaultCurrentPage),
~onCurrentPageChange=?onCurrentPageChange, ()),
                        children
                    );
            };
        

            module RowDetailState = {
                
                [@bs.obj] external makeProps : (~expandedRowIds: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~defaultExpandedRowIds: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~onExpandedRowIdsChange: 'any_r7yf=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "RowDetailState";
                let make = (
                    ~expandedRowIds: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~defaultExpandedRowIds: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~onExpandedRowIdsChange: option((array([ | `Int(int) | `Float(float) | `String(string)  ])) => unit)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~expandedRowIds=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), expandedRowIds),
~defaultExpandedRowIds=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), defaultExpandedRowIds),
~onExpandedRowIdsChange=?onExpandedRowIdsChange, ()),
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
                
                [@bs.obj] external makeProps : (~inputComponent: 'any_rmr2=?,
~messages: 'any_reqs=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "SearchPanel";
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
        

            module SearchState = {
                
                [@bs.obj] external makeProps : (~value: string=?,
~defaultValue: string=?,
~onValueChange: 'any_rtxo=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "SearchState";
                let make = (
                    ~value: option(string)=?,
~defaultValue: option(string)=?,
~onValueChange: option((string) => unit)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~value=?value,
~defaultValue=?defaultValue,
~onValueChange=?onValueChange, ()),
                        children
                    );
            };
        

            module SelectionState = {
                
                [@bs.obj] external makeProps : (~selection: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~defaultSelection: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~onSelectionChange: 'any_rwc7=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "SelectionState";
                let make = (
                    ~selection: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~defaultSelection: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~onSelectionChange: option((array([ | `Int(int) | `Float(float) | `String(string)  ])) => unit)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~selection=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), selection),
~defaultSelection=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), defaultSelection),
~onSelectionChange=?onSelectionChange, ()),
                        children
                    );
            };
        

            module SortingState = {
                

                [@bs.deriving jsConverter]
                type direction = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                    module Sorting {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                direction: direction
                            
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
                                            "direction",
                                            directionToJs(obj -> directionGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module DefaultSorting {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                direction: direction
                            
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
                                            "direction",
                                            directionToJs(obj -> directionGet)
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module ColumnExtensions {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            ,
                                
                                
                                sortingEnabled: bool
                            
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
                                            "sortingEnabled",
                                            obj -> sortingEnabledGet
                                            -> toJsUnsafe
                                        );
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~sorting: array(Sorting.t)=?,
~defaultSorting: array(DefaultSorting.t)=?,
~onSortingChange: 'any_rl9m=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~columnSortingEnabled: bool=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "SortingState";
                let make = (
                    ~sorting: option(array(Sorting.t))=?,
~defaultSorting: option(array(DefaultSorting.t))=?,
~onSortingChange: option((array(Sorting.t)) => unit)=?,
~columnExtensions: option(array(ColumnExtensions.t))=?,
~columnSortingEnabled: option(bool)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~sorting=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(Sorting.unwrap(item)), v)), sorting),
~defaultSorting=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(DefaultSorting.unwrap(item)), v)), defaultSorting),
~onSortingChange=?onSortingChange,
~columnExtensions=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(ColumnExtensions.unwrap(item)), v)), columnExtensions),
~columnSortingEnabled=?columnSortingEnabled, ()),
                        children
                    );
            };
        

            module StaticTableLayout = {
                
                [@bs.obj] external makeProps : (~headerRows: array('any_r44h)=?,
~bodyRows: array('any_rlbk),
~footerRows: array('any_rad6)=?,
~columns: array('any_rpbp),
~minWidth: 'number_4,
~containerComponent: 'genericCallback,
~tableComponent: 'genericCallback,
~headComponent: 'genericCallback=?,
~bodyComponent: 'genericCallback,
~footerComponent: 'genericCallback=?,
~rowComponent: 'genericCallback,
~cellComponent: 'genericCallback,
~getCellColSpan: 'genericCallback, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "StaticTableLayout";
                let make = (
                    ~headerRows: option(array('any_r44h))=?,
~bodyRows: array('any_rlbk),
~footerRows: option(array('any_rad6))=?,
~columns: array('any_rpbp),
~minWidth: [ | `Int(int) | `Float(float) ],
~containerComponent: 'genericCallback,
~tableComponent: 'genericCallback,
~headComponent: option('genericCallback)=?,
~bodyComponent: 'genericCallback,
~footerComponent: option('genericCallback)=?,
~rowComponent: 'genericCallback,
~cellComponent: 'genericCallback,
~getCellColSpan: 'genericCallback,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~headerRows=?headerRows,
~bodyRows=bodyRows,
~footerRows=?footerRows,
~columns=columns,
~minWidth=unwrapValue(minWidth),
~containerComponent=containerComponent,
~tableComponent=tableComponent,
~headComponent=?headComponent,
~bodyComponent=bodyComponent,
~footerComponent=?footerComponent,
~rowComponent=rowComponent,
~cellComponent=cellComponent,
~getCellColSpan=getCellColSpan, ()),
                        children
                    );
            };
        

            module SummaryState = {
                

                    module TotalItems {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            
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
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module GroupItems {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            
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
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                    module TreeItems {
                        [@bs.deriving abstract]
                        type t = {
                            
                                
                                
                                columnName: string
                            
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
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                
                [@bs.obj] external makeProps : (~totalItems: array(TotalItems.t)=?,
~groupItems: array(GroupItems.t)=?,
~treeItems: array(TreeItems.t)=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "SummaryState";
                let make = (
                    ~totalItems: option(array(TotalItems.t))=?,
~groupItems: option(array(GroupItems.t))=?,
~treeItems: option(array(TreeItems.t))=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~totalItems=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(TotalItems.unwrap(item)), v)), totalItems),
~groupItems=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(GroupItems.unwrap(item)), v)), groupItems),
~treeItems=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(TreeItems.unwrap(item)), v)), treeItems), ()),
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
                [@bs.obj] external makeProps : (~columnBands: array('any_rfpe)=?,
~cellComponent: 'any_rljn=?,
~rowComponent: 'any_r43l=?,
~bandedHeaderCellComponent: 'genericCallback=?,
~invisibleCellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableBandHeader";
                let make = (
                    ~columnBands: option(array('any_rfpe))=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rgtu,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r812, string) => 'any_rj4v
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
~onOrderChange: 'any_rlrt=?,
~tableContainerComponent: 'genericCallback=?,
~rowComponent: 'genericCallback=?,
~cellComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableColumnReordering";
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
~onColumnWidthsChange: 'any_r5q7=?,
~minColumnWidth: 'number_d=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableColumnResizing";
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
~emptyMessageComponent: 'any_r8sh=?,
~onHiddenColumnNamesChange: 'any_r9hp=?,
~messages: 'any_r1hr=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~columnTogglingEnabled: bool=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableColumnVisibility";
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
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_rxrp=?,
~headerCellComponent: 'any_rm29=?,
~commandComponent: 'any_rlxj=?,
~showAddCommand: bool=?,
~showEditCommand: bool=?,
~showDeleteCommand: bool=?,
~width: 'union_r76z=?,
~messages: 'any_rgb3=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableEditColumn";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rq8s,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rybc, string) => 'any_rnzy
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_rdtk,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ri6f,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r01y, string) => 'any_reh5
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
                [@bs.obj] external makeProps : (~rowHeight: 'number_j=?,
~cellComponent: 'any_rohw=?,
~rowComponent: 'any_r1jz=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableEditRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r6dr,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r9rq, string) => 'any_rvs9
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r3th,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rw44, string) => 'any_rcg9
                },"value": 'any_r7ay,"editingEnabled": bool,"onValueChange": ('any_r1at) => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rhzu,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_r5rp
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
                [@bs.obj] external makeProps : (~rowHeight: 'number_b=?,
~showFilterSelector: bool=?,
~messages: 'any_ra0i=?,
~cellComponent: 'any_rhae=?,
~rowComponent: 'any_rc7s=?,
~filterSelectorComponent: 'any_ri7s=?,
~iconComponent: 'any_rmvx=?,
~editorComponent: 'any_rt8r=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableFilterRow";
                let make = (
                    ~rowHeight: option([ | `Int(int) | `Float(float) ])=?,
~showFilterSelector: option(bool)=?,
~messages: option(Messages.t)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r3uc,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ra0m, string) => 'any_r6jf
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"filter": {.
                    "columnName": string,"operation": Js.t({..}),"value": string
                },"onFilter": ({.
                    "columnName": string,"operation": Js.t({..}),"value": string
                }) => unit,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_ri28, string) => 'any_rkan
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
                    "value": 'any_reh2,"disabled": bool,"onChange": (string) => unit,"getMessage": (string) => string
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
                
                [@bs.obj] external makeProps : (~cellComponent: 'any_ry0s=?,
~rowComponent: 'any_rowq=?,
~indentCellComponent: 'any_rof2=?,
~indentColumnWidth: 'number_8=?,
~showColumnsWhenGrouped: bool=?,
~columnExtensions: array(ColumnExtensions.t)=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableGroupRow";
                let make = (
                    ~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rae0,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rst6, string) => 'any_ruop
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_rd1g
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rr7g, string) => 'any_rcga
                },"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ryoi,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_rtv0
                }
                }) => ReasonReact.reactElement)=?,
~indentCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rlt9,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rfi0, string) => 'any_r1k9
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": {.
                    "key": [ | `Int(int) | `Float(float) | `String(string)  ],"value": 'any_rbsz
                },"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rc4i, string) => 'any_rhh6
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
~cellComponent: 'any_rh5u=?,
~rowComponent: 'any_re9a=?,
~messages: 'any_rbky=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableHeaderRow";
                let make = (
                    ~showSortingControls: option(bool)=?,
~showGroupingControls: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ru9v,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r62x, string) => 'any_rjy7
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r9aw, string) => 'any_r3oa
                },"showSortingControls": bool,"sortingEnabled": bool,"sortingDirection": sortingDirection,"onSort": ({.
                    "direction": [ | `Any('any_ruwf) | `Enum(direction_enum)  ],"keepOther": bool
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
        

            module TableLayout = {
                
                [@bs.obj] external makeProps : (~columns: array('any_r2bc),
~minColumnWidth: 'number_s,
~layoutComponent: 'genericCallback, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableLayout";
                let make = (
                    ~columns: array('any_r2bc),
~minColumnWidth: [ | `Int(int) | `Float(float) ],
~layoutComponent: 'genericCallback,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~columns=columns,
~minColumnWidth=unwrapValue(minColumnWidth),
~layoutComponent=layoutComponent, ()),
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
                [@bs.obj] external makeProps : (~contentComponent: 'any_rydt=?,
~toggleCellComponent: 'any_rdrm=?,
~cellComponent: 'any_rcys=?,
~rowComponent: 'any_rouy=?,
~toggleColumnWidth: 'number_7=?,
~rowHeight: 'number_3=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableRowDetail";
                let make = (
                    ~contentComponent: option(({.
                    "row": 'any_ram2
                }) => ReasonReact.reactElement)=?,
~toggleCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r0j7,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r528, string) => 'any_rrx9
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_rjx1,"expanded": bool,"onToggle": unit => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rron,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rq7c, string) => 'any_rkhw
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_r5cn,"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rnjo,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_rj4b
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
                [@bs.obj] external makeProps : (~headerCellComponent: 'any_rrqi=?,
~cellComponent: 'any_rnb6=?,
~rowComponent: 'genericCallback=?,
~highlightRow: bool=?,
~selectByRowClick: bool=?,
~showSelectAll: bool=?,
~showSelectionColumn: bool=?,
~selectionColumnWidth: 'number_t=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableSelection";
                let make = (
                    ~headerCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rqav,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rvw0, string) => 'any_ru3f
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"disabled": bool,"allSelected": bool,"someSelected": bool,"onToggle": (bool) => unit
                }) => ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rqeg,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r6fm, string) => 'any_r8b0
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"row": 'any_ryfm,"selected": bool,"onToggle": unit => unit
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
~totalRowComponent: 'any_rquk=?,
~groupRowComponent: 'any_ry1h=?,
~treeRowComponent: 'any_rh8v=?,
~totalCellComponent: 'any_r5iy=?,
~groupCellComponent: 'any_ropg=?,
~treeCellComponent: 'any_r17m=?,
~treeColumnCellComponent: 'any_rdzf=?,
~treeColumnContentComponent: 'any_r6pl=?,
~treeColumnIndentComponent: 'any_r4f5=?,
~itemComponent: ReasonReact.reactElement=?,
~messages: 'any_r60a=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableSummaryRow";
                let make = (
                    ~formatlessSummaryTypes: option(array(string))=?,
~totalRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~groupRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~treeRowComponent: option((Js.t({..})) => ReasonReact.reactElement)=?,
~totalCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rbdw,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r0e2, string) => 'any_rq9j
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rvoy, string) => 'any_rc5c
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~groupCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ryq7,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rqj6, string) => 'any_rxkp
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rqfz, string) => 'any_r1qz
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ruua,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rjsp, string) => 'any_rcp0
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rkog, string) => 'any_r1xm
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~treeColumnCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rahk,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r4yl, string) => 'any_rz5f
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rzaq, string) => 'any_rczp
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
~cellComponent: 'any_rbws=?,
~indentComponent: 'any_rljn=?,
~expandButtonComponent: 'any_r5gb=?,
~checkboxComponent: 'any_r3zc=?,
~contentComponent: 'any_rspq=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TableTreeColumn";
                let make = (
                    ~for_: option(string)=?,
~showSelectionControls: option(bool)=?,
~showSelectAll: option(bool)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r1uo,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rsoq, string) => 'any_rxfz
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_rmhf,"row": 'any_r0fy,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rfwt, string) => 'any_rqeb
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
~cellComponent: 'any_rs1j=?,
~rowComponent: 'any_r1lo=?,
~noDataCellComponent: 'any_r0ep=?,
~noDataRowComponent: 'any_ropm=?,
~stubRowComponent: 'any_rxv1=?,
~stubCellComponent: 'any_rydp=?,
~stubHeaderCellComponent: 'any_r0h3=?,
~columnExtensions: array(ColumnExtensions.t)=?,
~messages: 'any_roma=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "Table";
                let make = (
                    ~layoutComponent: option('genericCallback)=?,
~tableComponent: option(ReasonReact.reactElement)=?,
~headComponent: option(ReasonReact.reactElement)=?,
~bodyComponent: option(ReasonReact.reactElement)=?,
~footerComponent: option(ReasonReact.reactElement)=?,
~containerComponent: option(ReasonReact.reactElement)=?,
~cellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r8mw,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_retq, string) => 'any_r1es
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"value": 'any_rpyq,"row": 'any_rh3k,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_r8mb, string) => 'any_rgs3
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~rowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r96h,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement,"row": 'any_r20m
                }) => ReasonReact.reactElement)=?,
~noDataCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_ru50,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rheu, string) => 'any_r4ow
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ],"getMessage": (string) => string
                }) => ReasonReact.reactElement)=?,
~noDataRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r5gm,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubRowComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rhel,"height": [ | `Int(int) | `Float(float) ]
                },"children": ReasonReact.reactElement
                }) => ReasonReact.reactElement)=?,
~stubCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_rjy7,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rz5s, string) => 'any_ryvw
                },"width": [ | `Int(int) | `Float(float) ],"align": align
                },"colSpan": [ | `Int(int) | `Float(float) ],"rowSpan": [ | `Int(int) | `Float(float) ]
                }) => ReasonReact.reactElement)=?,
~stubHeaderCellComponent: option(({.
                    "tableRow": {.
                    "key": string,"type": string,"rowId": [ | `Int(int) | `Float(float) | `String(string)  ],"row": 'any_r6rr,"height": [ | `Int(int) | `Float(float) ]
                },"tableColumn": {.
                    "key": string,"type": string,"column": {.
                    "name": string,"title": string,"getCellValue": ('any_rax8, string) => 'any_r4zy
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
                
                [@bs.obj] external makeProps : (~rootComponent: 'any_r806=?,
~flexibleSpaceComponent: 'genericCallback=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "Toolbar";
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
        

            module TreeDataState = {
                
                [@bs.obj] external makeProps : (~expandedRowIds: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~defaultExpandedRowIds: array([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~onExpandedRowIdsChange: 'any_rytf=?, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "TreeDataState";
                let make = (
                    ~expandedRowIds: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~defaultExpandedRowIds: option(array([ | `Int(int) | `Float(float) | `String(string)  ]))=?,
~onExpandedRowIdsChange: option((array([ | `Int(int) | `Float(float) | `String(string)  ])) => unit)=?,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~expandedRowIds=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), expandedRowIds),
~defaultExpandedRowIds=?Js.Option.map([@bs] ((v) => Js.Array.map(item => toJsUnsafe(unwrapValue(item)), v)), defaultExpandedRowIds),
~onExpandedRowIdsChange=?onExpandedRowIdsChange, ()),
                        children
                    );
            };
        

            module VirtualTableLayout = {
                

                [@bs.deriving jsConverter]
                type height_enum = [
                    | [@bs.as "auto"] `Auto
                ];
                [@bs.obj] external makeProps : (~minWidth: 'number_6,
~minColumnWidth: 'number_j,
~height: 'union_r7lx,
~headerRows: array('any_r7p8)=?,
~bodyRows: array('any_r792),
~footerRows: array('any_rxse)=?,
~columns: array('any_r88k),
~cellComponent: 'genericCallback,
~rowComponent: 'genericCallback,
~bodyComponent: 'genericCallback,
~headComponent: 'genericCallback=?,
~footerComponent: 'genericCallback=?,
~tableComponent: 'genericCallback,
~headTableComponent: 'genericCallback=?,
~footerTableComponent: 'genericCallback=?,
~containerComponent: 'genericCallback,
~estimatedRowHeight: 'number_o,
~getCellColSpan: 'genericCallback, unit) => _ = "";
                [@bs.module "@devexpress/dx-react-grid"] external reactClass : ReasonReact.reactClass = "VirtualTableLayout";
                let make = (
                    ~minWidth: [ | `Int(int) | `Float(float) ],
~minColumnWidth: [ | `Int(int) | `Float(float) ],
~height: [ | `Int(int) | `Float(float) | `Enum(height_enum)  ],
~headerRows: option(array('any_r7p8))=?,
~bodyRows: array('any_r792),
~footerRows: option(array('any_rxse))=?,
~columns: array('any_r88k),
~cellComponent: 'genericCallback,
~rowComponent: 'genericCallback,
~bodyComponent: 'genericCallback,
~headComponent: option('genericCallback)=?,
~footerComponent: option('genericCallback)=?,
~tableComponent: 'genericCallback,
~headTableComponent: option('genericCallback)=?,
~footerTableComponent: option('genericCallback)=?,
~containerComponent: 'genericCallback,
~estimatedRowHeight: [ | `Int(int) | `Float(float) ],
~getCellColSpan: 'genericCallback,
                    children
                ) => ReasonReact.wrapJsForReason(
                        ~reactClass,
                        ~props=makeProps(~minWidth=unwrapValue(minWidth),
~minColumnWidth=unwrapValue(minColumnWidth),
~height=
                    (fun
                        | `Enum(v) => unwrapValue(`String(height_enumToJs(v)))
                        
                        | v => unwrapValue(v)
                    )(height)
                ,
~headerRows=?headerRows,
~bodyRows=bodyRows,
~footerRows=?footerRows,
~columns=columns,
~cellComponent=cellComponent,
~rowComponent=rowComponent,
~bodyComponent=bodyComponent,
~headComponent=?headComponent,
~footerComponent=?footerComponent,
~tableComponent=tableComponent,
~headTableComponent=?headTableComponent,
~footerTableComponent=?footerTableComponent,
~containerComponent=containerComponent,
~estimatedRowHeight=unwrapValue(estimatedRowHeight),
~getCellColSpan=getCellColSpan, ()),
                        children
                    );
            };
        