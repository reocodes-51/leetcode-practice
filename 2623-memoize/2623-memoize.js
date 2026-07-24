/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    
    const cache = new Map();                // create cache {}

    return function(...args) {
        const key = JSON.stringify(args); // unique key create

        if ( cache.has(key)) {             // check if already compute
            return cache.get(key); 
        }

        const result = fn(...args);         // if not then compute
        cache.set(key,result) ;
        return result ;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */