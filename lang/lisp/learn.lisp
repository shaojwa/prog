(defun memb (obj lst)
  (if (null lst)
    nil
    (if (eql (car lst) obj)
      lst
      (memb obj (cdr lst)))))

(defun add (a b)
  (print (+ a b)))

(defun ask ()
  (format t "please enter a number: ")
  (force-output nil)
  (let ((val (read)))
    (if (numberp val)
      val
      (ask))))
