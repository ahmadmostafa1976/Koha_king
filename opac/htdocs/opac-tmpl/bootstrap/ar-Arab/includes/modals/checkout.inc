<!-- Checkout form hidden by default, used for modal window -->
<div class="modal" id="checkoutModal" tabindex="-1" role="dialog" aria-labelledby="checkoutModalLabel" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <div class="modal-header">
 <h3 class="modal-title" id="checkoutModalLabel">إعارة ذاتية</h3>
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button">
 <span aria-hidden="true">&times;</span>
 </button>
 </div>
 <div class="modal-body">
 <div id="checkoutResults"></div>
 <div id="availabilityResult"></div>
 <div class="form-group">
 <label for="checkout_barcode">قم بإدخال باركود المادة: </label>
 <input type="text" name="checkout_barcode" id="checkout_barcode" required="required"></input>
 </div>
 <table id="checkoutsTable" class="table table-bordered table-striped" style="width:100%;">
 <thead>
 <tr>
 <th>الباركود</th>
 <th>عنوان</th>
 <th>رقم الاستدعاء</th>
 <th>تاريخ الاستحقاق</th>
 </tr>
 </thead>
 <tbody>
 </tbody>
 <tfoot>
 <tr>
 <td colspan="4" class="text-right"><span id="checkoutsCount"></span> تمت إعارة المادة</td>
 </tr>
 </tfoot>
 </table>
 </div>
 <div class="modal-footer">
 <button type="submit" id="checkoutSubmit" class="btn btn-primary">تقديم</button>
 <button type="button" id="checkoutClose" class="btn btn-default" data-dismiss="modal">إغلاق</button>
 </div>
 </div>
 </div>
</div>
