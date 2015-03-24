; 定义函数 
(defn parting
  "returns a String parting"
  [name]
  (str "Goodbye, " name)) ; concatenation

(println (parting "Mark")) ; -> Goodbye, Mark


; 函数的参数个数可以是不定的
(defn fun1 [arg1 & args]
    (println arg1 args))
(fun1 2 3 4) ;-> 2 (3 4)


; 函数定义多个参数参数列表及对应的方法体
(defn fun2 
    ([] (println "hello"))
    ([arg1] (println arg1))
    ([arg1 arg2] (println arg1 arg2))
    )
(fun2)     ;-> hello
(fun2 1)   ;-> 1
(fun2 2 3) ;-> 2 3


; Anonymous function 1
(println ((fn [param1] (str "param 1 is " param1)) "xxxx")) ;

; Anonymous function 2
(println (#(str "param 1 is "  %1) "xxxx")) ;
(println (#(str "param 1 is "  %) "xxxx")) ;
; (println (#(str "param 1 is " %1) )) ;




;; my-fn 指向 匿名函数
(def my-fn (fn [param1] (str "param is " param1)))
(println (my-fn "111"))
(println (my-fn "222"))


;; 函数作为参数
(defn callback [arg1 arg2] (+ arg1 arg2))

(defn caller [cb arg1] 
    (cb (+ 1 arg1) (+ 2 arg1)))
(println (caller callback 1)) ;-> 5


;; 函数作为返回值
(defn returnfun [] 
    (defn returnedfun [arg1] (+ arg1 1))
    )
(def ret (returnfun))
(println (ret 1)) ;-> 2


