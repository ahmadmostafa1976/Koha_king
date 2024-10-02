<!-- Cancel booking modal -->
<div class="modal" id="cancelBookingModal" tabindex="-1" role="dialog" aria-labelledby="cancelBookingLabel">
 <form method="get" id="cancelBookingForm">
 <div class="modal-dialog" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h4 class="modal-title" id="cancelBookingLabel">إلغاء الحجز</h4>
 </div>
 <div class="modal-body">
 <div id="cancel_booking_result"></div>
 <input type="hidden" name="booking_id" id="cancel_booking_id">
 <p>هل أنت متأكد من أنك تريد إلغاء هذا الحجز؟</p>
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <button type="submit" class="btn btn-danger">تأكيد</button>
 <button type="button" class="btn btn-default" data-dismiss="modal" aria-hidden="true">إلغاء</button>
 </div> <!-- /.modal-footer -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
 </form>
</div> <!-- /#cancelBookingModal -->
