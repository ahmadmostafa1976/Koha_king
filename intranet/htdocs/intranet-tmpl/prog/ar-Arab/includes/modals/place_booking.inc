<!-- Place booking modal -->
<div class="modal" id="placeBookingModal" tabindex="-1" role="dialog" aria-labelledby="placeBookingLabel">
 <form method="get" id="placeBookingForm">
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h4 class="modal-title" id="placeBookingLabel"></h4>
 </div>
 <div class="modal-body">
 <div id="booking_result"></div>
 <fieldset class="brief">
 <input type="hidden" name="biblio_id" id="booking_id">
 <input type="hidden" name="biblio_id" id="booking_biblio_id">
 <input type="hidden" name="start_date" id="booking_start_date">
 <input type="hidden" name="end_date" id="booking_end_date">
 <ol>
 <li>
 <label class="required" for="booking_patron_id">مستفيد: </label>
 <select name="booking_patron_id" id="booking_patron_id" required="required">
 <option></option>
 [% IF patron %]
 <option value="[% borrowernumber | uri %]" selected="selected">[% patron.firstname | html %] [% patron.surname | html %] ([% patron.cardnumber | html %] )</option>
 [% END %]
 </select>
 <div class="hint">إدخال رقم بطاقة المستفيد أو الاسم الجزئي</div>
 </li>
 <li>
 <label class="required" for="pickup_library_id">السحب في:</label>
 <select name="booking_pickup" id="pickup_library_id" required="required" disabled="disabled"></select>
 <span class="required">مطلوب</span>
 </li>
 <li>
 <label for="booking_item_id">المادة: </label>
 <select name="booking_item_id" id="booking_item_id" disabled="disabled">
 <option value="0">أي مادة</option>
 </select>
 </li>
 <li>
 <div id="period_fields">
 <label class="required" for="period">مواعيد الحجز: </label>
 <input type="text" id="period" name="period" class="flatpickr" data-flatpickr-futuredate="true" data-flatpickr-disable-shortcuts="true" required="required" disabled="disabled" autocomplete="off">
 <span class="required">مطلوب</span>
 </div>
 <div class="hint">تحديد تاريخ بدء الحجز وانتهائه</div>
 </li>
 </ol>
 </fieldset>
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <button type="submit" class="btn btn-primary">تقديم</button>
 <button type="button" class="btn btn-default" data-dismiss="modal" aria-hidden="true">إلغاء</button>
 </div> <!-- /.modal-footer -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </form>
</div> <!-- /#placeBookingModal -->
