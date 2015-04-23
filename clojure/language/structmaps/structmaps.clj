;ref: http://xumingming.sinaapp.com/302/clojure-functional-programming-for-the-jvm-clojure-tutorial/#struct-maps

;(def vehicle-struct (create-struct :make :model :year :color))
(defstruct vehicle-struct :make :model :year :color)
(def vehicle (struct vehicle-struct "Toyota" "Prius" 2009))
(println vehicle)

;类似getXXX, 比hash 查找快
(def make_accessor (accessor vehicle-struct :make))
(println (make_accessor vehicle))

; hash方式,功能与上面一样，但是慢一些
(println (vehicle :make))
(println (:make vehicle))
