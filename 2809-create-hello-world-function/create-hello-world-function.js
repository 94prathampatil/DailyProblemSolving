/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const f = () => {
        return "Hello World";
    }

    return function(...args) {
        return f();
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */