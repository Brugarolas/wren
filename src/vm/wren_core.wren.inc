// Generated automatically from wren_core.wren. Do not edit.
static const char* coreModuleSource =
"class Bool {}\n"
"class Fiber {}\n"
"class Fn {\n"
"  !~(arg) { !(arg ~~ this) }\n"
"}\n"
"class Null {}\n"
"class Num {\n"
"  trait(Key) {\n"
"    if (Key is Class) {\n"
"      var Klass = Num.traits[Key.name]\n"
"      return Klass.new(this)\n"
"    }\n"
"    return Num.traits[Key].call(this)\n"
"  }\n"
"\n"
"  static trait(Key) {\n"
"    if (Key is Class) {\n"
"      var Klass = Num.traits[Key.name]\n"
"      return Klass\n"
"    }\n"
"    return Num.traits[Key]\n"
"  }\n"
"\n"
"  static trait(Key, Value) {\n"
"    if (Key is Class) {\n"
"      return Num.traits[Key.name] = Value\n"
"    }\n"
"    return Num.traits[Key] = Value\n"
"  }\n"
"\n"
"  static use(Key) {\n"
"    return Num.trait(Key, Key)\n"
"  }\n"
"  \n"
"  static traits {\n"
"    if (!__traits) {\n"
"      __traits = Map.new()\n"
"    }\n"
"    return __traits\n"
"  }\n"
"}\n"
"\n"
"class Fn {\n"
"  callAll(args) {\n"
"    var arity = args.count\n"
"\n"
"    if (arity ==  0) return call()\n"
"    if (arity ==  1) return call(args[0])\n"
"    if (arity ==  2) return call(args[0], args[1])\n"
"    if (arity ==  3) return call(args[0], args[1], args[2])\n"
"    if (arity ==  4) return call(args[0], args[1], args[2], args[3])\n"
"    if (arity ==  5) return call(args[0], args[1], args[2], args[3], args[4])\n"
"    if (arity ==  6) return call(args[0], args[1], args[2], args[3], args[4], args[5])\n"
"    if (arity ==  7) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6])\n"
"    if (arity ==  8) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7])\n"
"    if (arity ==  9) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8])\n"
"    if (arity == 10) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9])\n"
"    if (arity == 11) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10])\n"
"    if (arity == 12) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11])\n"
"    if (arity == 13) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12])\n"
"    if (arity == 14) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13])\n"
"    if (arity == 15) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14])\n"
"                     return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14], args[15])\n"
"  }\n"
"}\n"
"\n"
"class Sequence {\n"
"  all(f) {\n"
"    var result = true\n"
"    for (element in this) {\n"
"      result = f.call(element)\n"
"      if (!result) return result\n"
"    }\n"
"    return result\n"
"  }\n"
"\n"
"  any(f) {\n"
"    var result = false\n"
"    for (element in this) {\n"
"      result = f.call(element)\n"
"      if (result) return result\n"
"    }\n"
"    return result\n"
"  }\n"
"\n"
"  contains(element) {\n"
"    for (item in this) {\n"
"      if (element == item) return true\n"
"    }\n"
"    return false\n"
"  }\n"
"\n"
"  ~~(element) { contains(element) }\n"
"\n"
"  !~(element) {\n"
"    return !contains(element)\n"
"  }\n"
"\n"
"  count {\n"
"    var result = 0\n"
"    for (element in this) {\n"
"      result = result + 1\n"
"    }\n"
"    return result\n"
"  }\n"
"\n"
"  count(f) {\n"
"    var result = 0\n"
"    for (element in this) {\n"
"      if (f.call(element)) result = result + 1\n"
"    }\n"
"    return result\n"
"  }\n"
"\n"
"  each(f) {\n"
"    for (element in this) {\n"
"      f.call(element)\n"
"    }\n"
"  }\n"
"\n"
"  find(predicate) { find(iterate(null), predicate) }\n"
"\n"
"  find(it, predicate) {\n"
"    while(it) {\n"
"      if (predicate.call(iteratorValue(it))) break\n"
"      it = iterate(it)\n"
"    }\n"
"    return it\n"
"  }\n"
"\n"
"  isEmpty { iterate(null) ? false : true }\n"
"\n"
"  map(transformation) { MapSequence.new(this, transformation) }\n"
"\n"
"  skip(count) {\n"
"    if (!(count is Num) || !count.isInteger || count < 0) {\n"
"      Fiber.abort(\"Count must be a non-negative integer.\")\n"
"    }\n"
"\n"
"    return SkipSequence.new(this, count)\n"
"  }\n"
"\n"
"  take(count) {\n"
"    if (!(count is Num) || !count.isInteger || count < 0) {\n"
"      Fiber.abort(\"Count must be a non-negative integer.\")\n"
"    }\n"
"\n"
"    return TakeSequence.new(this, count)\n"
"  }\n"
"\n"
"  where(predicate) { WhereSequence.new(this, predicate) }\n"
"\n"
"  reduce(acc, f) {\n"
"    for (element in this) {\n"
"      acc = f.call(acc, element)\n"
"    }\n"
"    return acc\n"
"  }\n"
"\n"
"  reduce(f) {\n"
"    var iter = iterate(null)\n"
"    if (!iter) Fiber.abort(\"Can't reduce an empty sequence.\")\n"
"\n"
"    // Seed with the first element.\n"
"    var result = iteratorValue(iter)\n"
"    while (iter = iterate(iter)) {\n"
"      result = f.call(result, iteratorValue(iter))\n"
"    }\n"
"\n"
"    return result\n"
"  }\n"
"\n"
"  join() { join(\"\") }\n"
"\n"
"  join(sep) {\n"
"    var first = true\n"
"    var result = \"\"\n"
"\n"
"    for (element in this) {\n"
"      if (!first) result = result + sep\n"
"      first = false\n"
"      result = result + element.toString\n"
"    }\n"
"\n"
"    return result\n"
"  }\n"
"\n"
"  toList {\n"
"    var result = List.new()\n"
"    for (element in this) {\n"
"      result.add(element)\n"
"    }\n"
"    return result\n"
"  }\n"
"}\n"
"\n"
"class MapSequence is Sequence {\n"
"  construct new(sequence, fn) {\n"
"    _sequence = sequence\n"
"    _fn = fn\n"
"  }\n"
"\n"
"  iterate(iterator) { _sequence.iterate(iterator) }\n"
"  iteratorValue(iterator) { _fn.call(_sequence.iteratorValue(iterator)) }\n"
"}\n"
"\n"
"class SkipSequence is Sequence {\n"
"  construct new(sequence, count) {\n"
"    _sequence = sequence\n"
"    _count = count\n"
"  }\n"
"\n"
"  iterate(iterator) {\n"
"    if (iterator) {\n"
"      return _sequence.iterate(iterator)\n"
"    } else {\n"
"      iterator = _sequence.iterate(iterator)\n"
"      var count = _count\n"
"      while (count > 0 && iterator) {\n"
"        iterator = _sequence.iterate(iterator)\n"
"        count = count - 1\n"
"      }\n"
"      return iterator\n"
"    }\n"
"  }\n"
"\n"
"  iteratorValue(iterator) { _sequence.iteratorValue(iterator) }\n"
"}\n"
"\n"
"class TakeSequence is Sequence {\n"
"  construct new(sequence, count) {\n"
"    _sequence = sequence\n"
"    _count = count\n"
"  }\n"
"\n"
"  iterate(iterator) {\n"
"    if (!iterator) _taken = 1 else _taken = _taken + 1\n"
"    return _taken > _count ? null : _sequence.iterate(iterator)\n"
"  }\n"
"\n"
"  iteratorValue(iterator) { _sequence.iteratorValue(iterator) }\n"
"}\n"
"\n"
"class WhereSequence is Sequence {\n"
"  construct new(sequence, fn) {\n"
"    _sequence = sequence\n"
"    _fn = fn\n"
"  }\n"
"\n"
"  iterate(iterator) {\n"
"    while (iterator = _sequence.iterate(iterator)) {\n"
"      if (_fn.call(_sequence.iteratorValue(iterator))) break\n"
"    }\n"
"    return iterator\n"
"  }\n"
"\n"
"  iteratorValue(iterator) { _sequence.iteratorValue(iterator) }\n"
"}\n"
"\n"
"class SeqMatchIfContains {\n"
"  construct new(seq) {\n"
"    _seq = seq\n"
"  }\n"
"\n"
"  ~~(needle) { _seq.contains(needle) }\n"
"  !~(needle) { !_seq.contains(needle) }\n"
"}\n"
"\n"
"class String is Sequence {\n"
"  trait(key) {String.traits[key].call(this)}\n"
"  trait(key, value) {String.trait(key, value)}\n"
"  traits {String.traits}\n"
"  \n"
"  static trait(key) {String.traits[key]}\n"
"  static trait(key, value) {String.traits[key] = value}\n"
"  \n"
"  static traits {\n"
"    if (!__traits) {\n"
"      __traits = Map.new()\n"
"    }\n"
"    return __traits\n"
"  }\n"
"\n"
"  bytes { StringByteSequence.new(this) }\n"
"  codePoints { StringCodePointSequence.new(this) }\n"
"\n"
"  part { SeqMatchIfContains.new(this) }\n"
"\n"
"  split(delimiter) {\n"
"    if (!(delimiter is String) || delimiter.isEmpty) {\n"
"      Fiber.abort(\"Delimiter must be a non-empty string.\")\n"
"    }\n"
"\n"
"    var result = []\n"
"\n"
"    var last = 0\n"
"    var index = 0\n"
"\n"
"    var delimSize = delimiter.byteCount_\n"
"    var size = byteCount_\n"
"\n"
"    while (last < size && (index = indexOf(delimiter, last)) != -1) {\n"
"      result.add(this[last...index])\n"
"      last = index + delimSize\n"
"    }\n"
"\n"
"    if (last < size) {\n"
"      result.add(this[last..-1])\n"
"    } else {\n"
"      result.add(\"\")\n"
"    }\n"
"    return result\n"
"  }\n"
"\n"
"  replace(from, to) {\n"
"    if (!(from is String) || from.isEmpty) {\n"
"      Fiber.abort(\"From must be a non-empty string.\")\n"
"    } else if (!(to is String)) {\n"
"      Fiber.abort(\"To must be a string.\")\n"
"    }\n"
"\n"
"    var result = \"\"\n"
"\n"
"    var last = 0\n"
"    var index = 0\n"
"\n"
"    var fromSize = from.byteCount_\n"
"    var size = byteCount_\n"
"\n"
"    while (last < size && (index = indexOf(from, last)) != -1) {\n"
"      result = result + this[last...index] + to\n"
"      last = index + fromSize\n"
"    }\n"
"\n"
"    if (last < size) result = result + this[last..-1]\n"
"\n"
"    return result\n"
"  }\n"
"\n"
"  lower {\n"
"    var output = \"\"\n"
"    for (c in codePoints) {\n"
"      if ((c >= 65 && c <= 90) || (c >= 192 && c <= 214) || (c >= 216 && c <= 222)) {\n"
"        c = c + 32\n"
"      }\n"
"      output = output + String.fromCodePoint(c)\n"
"    }\n"
"    return output\n"
"  }\n"
"\n"
"  trim() { trim_(\"\\t\\r\\n \", true, true) }\n"
"  trim(chars) { trim_(chars, true, true) }\n"
"  trimEnd() { trim_(\"\\t\\r\\n \", false, true) }\n"
"  trimEnd(chars) { trim_(chars, false, true) }\n"
"  trimStart() { trim_(\"\\t\\r\\n \", true, false) }\n"
"  trimStart(chars) { trim_(chars, true, false) }\n"
"\n"
"  trim_(chars, trimStart, trimEnd) {\n"
"    if (!(chars is String)) {\n"
"      Fiber.abort(\"Characters must be a string.\")\n"
"    }\n"
"\n"
"    var codePoints = chars.codePoints.toList\n"
"\n"
"    var start\n"
"    if (trimStart) {\n"
"      while (start = iterate(start)) {\n"
"        if (!codePoints.contains(codePointAt_(start))) break\n"
"      }\n"
"\n"
"      if (start == false) return \"\"\n"
"    } else {\n"
"      start = 0\n"
"    }\n"
"\n"
"    var end\n"
"    if (trimEnd) {\n"
"      end = byteCount_ - 1\n"
"      while (end >= start) {\n"
"        var codePoint = codePointAt_(end)\n"
"        if (codePoint != -1 && !codePoints.contains(codePoint)) break\n"
"        end = end - 1\n"
"      }\n"
"\n"
"      if (end < start) return \"\"\n"
"    } else {\n"
"      end = -1\n"
"    }\n"
"\n"
"    return this[start..end]\n"
"  }\n"
"\n"
"  *(count) {\n"
"    if (!(count is Num) || !count.isInteger || count < 0) {\n"
"      Fiber.abort(\"Count must be a non-negative integer.\")\n"
"    }\n"
"\n"
"    var result = \"\"\n"
"    for (i in 0...count) {\n"
"      result = result + this\n"
"    }\n"
"    return result\n"
"  }\n"
"\n"
"  <  (other) { compareTo(other) <  0 }\n"
"  <= (other) { compareTo(other) <= 0 }\n"
"  >  (other) { compareTo(other) >  0 }\n"
"  >= (other) { compareTo(other) >= 0 }\n"
"}\n"
"\n"
"class StringByteSequence is Sequence {\n"
"  construct new(string) {\n"
"    _string = string\n"
"  }\n"
"\n"
"  [index] { _string.byteAt_(index) }\n"
"  iterate(iterator) { _string.iterateByte_(iterator) }\n"
"  iteratorValue(iterator) { _string.byteAt_(iterator) }\n"
"\n"
"  count { _string.byteCount_ }\n"
"}\n"
"\n"
"class StringCodePointSequence is Sequence {\n"
"  construct new(string) {\n"
"    _string = string\n"
"  }\n"
"\n"
"  [index] { _string.codePointAt_(index) }\n"
"  iterate(iterator) { _string.iterate(iterator) }\n"
"  iteratorValue(iterator) { _string.codePointAt_(iterator) }\n"
"\n"
"  count { _string.count }\n"
"}\n"
"\n"
"class List is Sequence {\n"
"  addAll(other) {\n"
"    for (element in other) {\n"
"      add(element)\n"
"    }\n"
"    return other\n"
"  }\n"
"\n"
"  sort() { sort {|low, high| low < high } }\n"
"\n"
"  sort(comparer) {\n"
"    if (!(comparer is Fn)) {\n"
"      Fiber.abort(\"Comparer must be a function.\")\n"
"    }\n"
"    quicksort_(0, count - 1, comparer)\n"
"    return this\n"
"  }\n"
"\n"
"  quicksort_(low, high, comparer) {\n"
"    if (low < high) {\n"
"      var p = partition_(low, high, comparer)\n"
"      quicksort_(low, p, comparer)\n"
"      quicksort_(p + 1, high, comparer)\n"
"    }\n"
"  }\n"
"\n"
"  partition_(low, high, comparer) {\n"
"    var mid = ((low + high) / 2).floor\n"
"    var p = this[mid]\n"
"    var i = low - 1\n"
"    var j = high + 1\n"
"    while (true) {\n"
"      while (true) {\n"
"        i = i + 1\n"
"        if (!comparer.call(this[i], p)) break\n"
"      }\n"
"      while (true) {\n"
"        j = j - 1\n"
"        if (!comparer.call(p, this[j])) break\n"
"      }\n"
"      if (i >= j) return j\n"
"      swap(i, j)\n"
"    }\n"
"  }\n"
"\n"
"  toString { \"[%(join(\", \"))]\" }\n"
"\n"
"  +(other) {\n"
"    var result = this[0..-1]\n"
"    for (element in other) {\n"
"      result.add(element)\n"
"    }\n"
"    return result\n"
"  }\n"
"\n"
"  *(count) {\n"
"    if (!(count is Num) || !count.isInteger || count < 0) {\n"
"      Fiber.abort(\"Count must be a non-negative integer.\")\n"
"    }\n"
"\n"
"    var result = []\n"
"    for (i in 0...count) {\n"
"      result.addAll(this)\n"
"    }\n"
"    return result\n"
"  }\n"
"}\n"
"\n"
"class Map is Sequence {\n"
"  keys { MapKeySequence.new(this) }\n"
"  values { MapValueSequence.new(this) }\n"
"\n"
"  toString {\n"
"    var first = true\n"
"    var result = \"{\"\n"
"\n"
"    for (key in keys) {\n"
"      if (!first) result = result + \", \"\n"
"      first = false\n"
"      result = result + \"%(key): %(this[key])\"\n"
"    }\n"
"\n"
"    return result + \"}\"\n"
"  }\n"
"\n"
"  iteratorValue(iterator) {\n"
"    return MapEntry.new(\n"
"        keyIteratorValue_(iterator),\n"
"        valueIteratorValue_(iterator))\n"
"  }\n"
"}\n"
"\n"
"class MapEntry {\n"
"  construct new(key, value) {\n"
"    _key = key\n"
"    _value = value\n"
"  }\n"
"\n"
"  key { _key }\n"
"  value { _value }\n"
"\n"
"  toString { \"%(_key):%(_value)\" }\n"
"}\n"
"\n"
"class MapKeySequence is Sequence {\n"
"  construct new(map) {\n"
"    _map = map\n"
"  }\n"
"\n"
"  iterate(n) { _map.iterate(n) }\n"
"  iteratorValue(iterator) { _map.keyIteratorValue_(iterator) }\n"
"}\n"
"\n"
"class MapValueSequence is Sequence {\n"
"  construct new(map) {\n"
"    _map = map\n"
"  }\n"
"\n"
"  iterate(n) { _map.iterate(n) }\n"
"  iteratorValue(iterator) { _map.valueIteratorValue_(iterator) }\n"
"}\n"
"\n"
"class Range is Sequence {}\n"
"\n"
"class System {\n"
"  static print() {\n"
"    writeString_(\"\\n\")\n"
"  }\n"
"\n"
"  static print(obj) {\n"
"    writeObject_(obj)\n"
"    writeString_(\"\\n\")\n"
"    return obj\n"
"  }\n"
"\n"
"  static printAll(sequence) {\n"
"    for (object in sequence) writeObject_(object)\n"
"    writeString_(\"\\n\")\n"
"  }\n"
"\n"
"  static write(obj) {\n"
"    writeObject_(obj)\n"
"    return obj\n"
"  }\n"
"\n"
"  static writeAll(sequence) {\n"
"    for (object in sequence) writeObject_(object)\n"
"  }\n"
"\n"
"  static writeObject_(obj) {\n"
"    var string = obj.toString\n"
"    if (string is String) {\n"
"      writeString_(string)\n"
"    } else {\n"
"      writeString_(\"[invalid toString]\")\n"
"    }\n"
"  }\n"
"}\n"
"\n"
"class ClassAttributes {\n"
"  self { _attributes }\n"
"  methods { _methods }\n"
"  construct new(attributes, methods) {\n"
"    _attributes = attributes\n"
"    _methods = methods\n"
"  }\n"
"  toString { \"attributes:%(_attributes) methods:%(_methods)\" }\n"
"}\n";
