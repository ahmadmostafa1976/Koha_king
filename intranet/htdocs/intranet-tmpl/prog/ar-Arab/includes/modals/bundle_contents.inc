<!-- Bundle contents modal -->
<div class="modal printable" id="bundleContentsModal" tabindex="-1" role="dialog" aria-labelledby="bundleContentsLabel">
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h4 class="modal-title" id="bundleContentsLabel">محتويات الحزمة لـ [% item.barcode | html %]</h4>
 </div>
 <div class="modal-body">
 <table style="width:100%">
 <thead>
 <tr>
 <th>الباركود</th>
 <th>عنوان</th>
 </tr>
 </thead>
 <tbody>
 [% FOREACH bundle_item IN bundle_items %]
 <tr>
 <td>[% bundle_item.barcode | html %]</td>
 <td>[% INCLUDE 'biblio-title.inc' biblio=bundle_item.biblio %]</td>
 </tr>
 [% END %]
 </tbody>
 <tfoot>
 </tfoot>
 </table>
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-dismiss="modal">إغلاق</button>
 <button type="button" class="printModal btn btn-primary"><i class="fa fa-print"></i> طباعة</button>
 </div> <!-- /.modal-footer -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#bundleContentsModal -->
