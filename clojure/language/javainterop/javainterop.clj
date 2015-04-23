; ref http://xumingming.sinaapp.com/302/clojure-functional-programming-for-the-jvm-clojure-tutorial/#java-interoperability

; 导入java类
(import '(java.util Date)) 

; 创建java对象
; 方式1:
(def date1 (new Date))
; 方式2:
(def date2 (Date.))


; 调用java对象的方法
; 方式1: 定义宏的时候用得比多
(println (. date1 getTime))
(println (. date2 getTime))
; 方式2: 这种方式比较推荐
(println (.getTime date1))
(println (.getTime date2))
