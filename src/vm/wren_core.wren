class Bool {}
class Fiber {}
class Fn {
  !~(arg) { !(arg ~~ this) }
}
class Null {}
class Num {
  trait(Key) {
    if (Key is Class) {
      var Klass = Num.traits[Key.name]
      return Klass.new(this)
    }
    return Num.traits[Key].call(this)
  }

  static trait(Key) {
    if (Key is Class) {
      var Klass = Num.traits[Key.name]
      return Klass
    }
    return Num.traits[Key]
  }

  static trait(Key, Value) {
    if (Key is Class) {
      return Num.traits[Key.name] = Value
    }
    return Num.traits[Key] = Value
  }

  static use(Key) {
    return Num.trait(Key, Key)
  }
  
  static traits {
    if (!__traits) {
      __traits = Map.new()
    }
    return __traits
  }
}

class Fn {
  callAll(args) {
    var arity = args.count

    if (arity ==  0) return call()
    if (arity ==  1) return call(args[0])
    if (arity ==  2) return call(args[0], args[1])
    if (arity ==  3) return call(args[0], args[1], args[2])
    if (arity ==  4) return call(args[0], args[1], args[2], args[3])
    if (arity ==  5) return call(args[0], args[1], args[2], args[3], args[4])
    if (arity ==  6) return call(args[0], args[1], args[2], args[3], args[4], args[5])
    if (arity ==  7) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6])
    if (arity ==  8) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7])
    if (arity ==  9) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8])
    if (arity == 10) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9])
    if (arity == 11) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10])
    if (arity == 12) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11])
    if (arity == 13) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12])
    if (arity == 14) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13])
    if (arity == 15) return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14])
                     return call(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14], args[15])
  }
}

class Sequence {
  all(f) {
    var result = true
    for (element in this) {
      result = f.call(element)
      if (!result) return result
    }
    return result
  }

  any(f) {
    var result = false
    for (element in this) {
      result = f.call(element)
      if (result) return result
    }
    return result
  }

  contains(element) {
    for (item in this) {
      if (element == item) return true
    }
    return false
  }

  ~~(element) { contains(element) }

  !~(element) {
    return !contains(element)
  }

  count {
    var result = 0
    for (element in this) {
      result = result + 1
    }
    return result
  }

  count(f) {
    var result = 0
    for (element in this) {
      if (f.call(element)) result = result + 1
    }
    return result
  }

  each(f) {
    for (element in this) {
      f.call(element)
    }
  }

  find(predicate) { find(iterate(null), predicate) }

  find(it, predicate) {
    while(it) {
      if (predicate.call(iteratorValue(it))) break
      it = iterate(it)
    }
    return it
  }

  isEmpty { iterate(null) ? false : true }

  map(transformation) { MapSequence.new(this, transformation) }

  skip(count) {
    if (!(count is Num) || !count.isInteger || count < 0) {
      Fiber.abort("Count must be a non-negative integer.")
    }

    return SkipSequence.new(this, count)
  }

  take(count) {
    if (!(count is Num) || !count.isInteger || count < 0) {
      Fiber.abort("Count must be a non-negative integer.")
    }

    return TakeSequence.new(this, count)
  }

  where(predicate) { WhereSequence.new(this, predicate) }

  reduce(acc, f) {
    for (element in this) {
      acc = f.call(acc, element)
    }
    return acc
  }

  reduce(f) {
    var iter = iterate(null)
    if (!iter) Fiber.abort("Can't reduce an empty sequence.")

    // Seed with the first element.
    var result = iteratorValue(iter)
    while (iter = iterate(iter)) {
      result = f.call(result, iteratorValue(iter))
    }

    return result
  }

  join() { join("") }

  join(sep) {
    var first = true
    var result = ""

    for (element in this) {
      if (!first) result = result + sep
      first = false
      result = result + element.toString
    }

    return result
  }

  toList {
    var result = List.new()
    for (element in this) {
      result.add(element)
    }
    return result
  }
}

class MapSequence is Sequence {
  construct new(sequence, fn) {
    _sequence = sequence
    _fn = fn
  }

  iterate(iterator) { _sequence.iterate(iterator) }
  iteratorValue(iterator) { _fn.call(_sequence.iteratorValue(iterator)) }
}

class SkipSequence is Sequence {
  construct new(sequence, count) {
    _sequence = sequence
    _count = count
  }

  iterate(iterator) {
    if (iterator) {
      return _sequence.iterate(iterator)
    } else {
      iterator = _sequence.iterate(iterator)
      var count = _count
      while (count > 0 && iterator) {
        iterator = _sequence.iterate(iterator)
        count = count - 1
      }
      return iterator
    }
  }

  iteratorValue(iterator) { _sequence.iteratorValue(iterator) }
}

class TakeSequence is Sequence {
  construct new(sequence, count) {
    _sequence = sequence
    _count = count
  }

  iterate(iterator) {
    if (!iterator) _taken = 1 else _taken = _taken + 1
    return _taken > _count ? null : _sequence.iterate(iterator)
  }

  iteratorValue(iterator) { _sequence.iteratorValue(iterator) }
}

class WhereSequence is Sequence {
  construct new(sequence, fn) {
    _sequence = sequence
    _fn = fn
  }

  iterate(iterator) {
    while (iterator = _sequence.iterate(iterator)) {
      if (_fn.call(_sequence.iteratorValue(iterator))) break
    }
    return iterator
  }

  iteratorValue(iterator) { _sequence.iteratorValue(iterator) }
}

class SeqMatchIfContains {
  construct new(seq) {
    _seq = seq
  }

  ~~(needle) { _seq.contains(needle) }
  !~(needle) { !_seq.contains(needle) }
}

class String is Sequence {
  trait(key) {String.traits[key].call(this)}
  trait(key, value) {String.trait(key, value)}
  traits {String.traits}
  
  static trait(key) {String.traits[key]}
  static trait(key, value) {String.traits[key] = value}
  
  static traits {
    if (!__traits) {
      __traits = Map.new()
    }
    return __traits
  }

  bytes { StringByteSequence.new(this) }
  codePoints { StringCodePointSequence.new(this) }

  part { SeqMatchIfContains.new(this) }

  split(delimiter) {
    if (!(delimiter is String) || delimiter.isEmpty) {
      Fiber.abort("Delimiter must be a non-empty string.")
    }

    var result = []

    var last = 0
    var index = 0

    var delimSize = delimiter.byteCount_
    var size = byteCount_

    while (last < size && (index = indexOf(delimiter, last)) != -1) {
      result.add(this[last...index])
      last = index + delimSize
    }

    if (last < size) {
      result.add(this[last..-1])
    } else {
      result.add("")
    }
    return result
  }

  replace(from, to) {
    if (!(from is String) || from.isEmpty) {
      Fiber.abort("From must be a non-empty string.")
    } else if (!(to is String)) {
      Fiber.abort("To must be a string.")
    }

    var result = ""

    var last = 0
    var index = 0

    var fromSize = from.byteCount_
    var size = byteCount_

    while (last < size && (index = indexOf(from, last)) != -1) {
      result = result + this[last...index] + to
      last = index + fromSize
    }

    if (last < size) result = result + this[last..-1]

    return result
  }

  lower {
    var output = ""
    for (c in codePoints) {
      if ((c >= 65 && c <= 90) || (c >= 192 && c <= 214) || (c >= 216 && c <= 222)) {
        c = c + 32
      }
      output = output + String.fromCodePoint(c)
    }
    return output
  }

  trim() { trim_("\t\r\n ", true, true) }
  trim(chars) { trim_(chars, true, true) }
  trimEnd() { trim_("\t\r\n ", false, true) }
  trimEnd(chars) { trim_(chars, false, true) }
  trimStart() { trim_("\t\r\n ", true, false) }
  trimStart(chars) { trim_(chars, true, false) }

  trim_(chars, trimStart, trimEnd) {
    if (!(chars is String)) {
      Fiber.abort("Characters must be a string.")
    }

    var codePoints = chars.codePoints.toList

    var start
    if (trimStart) {
      while (start = iterate(start)) {
        if (!codePoints.contains(codePointAt_(start))) break
      }

      if (start == false) return ""
    } else {
      start = 0
    }

    var end
    if (trimEnd) {
      end = byteCount_ - 1
      while (end >= start) {
        var codePoint = codePointAt_(end)
        if (codePoint != -1 && !codePoints.contains(codePoint)) break
        end = end - 1
      }

      if (end < start) return ""
    } else {
      end = -1
    }

    return this[start..end]
  }

  *(count) {
    if (!(count is Num) || !count.isInteger || count < 0) {
      Fiber.abort("Count must be a non-negative integer.")
    }

    var result = ""
    for (i in 0...count) {
      result = result + this
    }
    return result
  }
 
  <  (other) { compareTo(other) <  0 }
  <= (other) { compareTo(other) <= 0 }
  >  (other) { compareTo(other) >  0 }
  >= (other) { compareTo(other) >= 0 }
}

class StringByteSequence is Sequence {
  construct new(string) {
    _string = string
  }

  [index] { _string.byteAt_(index) }
  iterate(iterator) { _string.iterateByte_(iterator) }
  iteratorValue(iterator) { _string.byteAt_(iterator) }

  count { _string.byteCount_ }
}

class StringCodePointSequence is Sequence {
  construct new(string) {
    _string = string
  }

  [index] { _string.codePointAt_(index) }
  iterate(iterator) { _string.iterate(iterator) }
  iteratorValue(iterator) { _string.codePointAt_(iterator) }

  count { _string.count }
}

class List is Sequence {
  addAll(other) {
    for (element in other) {
      add(element)
    }
    return other
  }

  sort() { sort {|low, high| low < high } }

  sort(comparer) {
    if (!(comparer is Fn)) {
      Fiber.abort("Comparer must be a function.")
    }
    quicksort_(0, count - 1, comparer)
    return this
  }

  quicksort_(low, high, comparer) {
    if (low < high) {
      var p = partition_(low, high, comparer)
      quicksort_(low, p, comparer)
      quicksort_(p + 1, high, comparer)
    }
  }

  partition_(low, high, comparer) {
    var mid = ((low + high) / 2).floor
    var p = this[mid]
    var i = low - 1
    var j = high + 1
    while (true) {
      while (true) {
        i = i + 1
        if (!comparer.call(this[i], p)) break
      }
      while (true) {
        j = j - 1
        if (!comparer.call(p, this[j])) break
      }
      if (i >= j) return j
      swap(i, j)
    }
  }

  toString { "[%(join(", "))]" }

  +(other) {
    var result = this[0..-1]
    for (element in other) {
      result.add(element)
    }
    return result
  }

  *(count) {
    if (!(count is Num) || !count.isInteger || count < 0) {
      Fiber.abort("Count must be a non-negative integer.")
    }

    var result = []
    for (i in 0...count) {
      result.addAll(this)
    }
    return result
  }
}

class Map is Sequence {
  keys { MapKeySequence.new(this) }
  values { MapValueSequence.new(this) }

  toString {
    var first = true
    var result = "{"

    for (key in keys) {
      if (!first) result = result + ", "
      first = false
      result = result + "%(key): %(this[key])"
    }

    return result + "}"
  }

  iteratorValue(iterator) {
    return MapEntry.new(
        keyIteratorValue_(iterator),
        valueIteratorValue_(iterator))
  }
}

class MapEntry {
  construct new(key, value) {
    _key = key
    _value = value
  }

  key { _key }
  value { _value }

  toString { "%(_key):%(_value)" }
}

class MapKeySequence is Sequence {
  construct new(map) {
    _map = map
  }

  iterate(n) { _map.iterate(n) }
  iteratorValue(iterator) { _map.keyIteratorValue_(iterator) }
}

class MapValueSequence is Sequence {
  construct new(map) {
    _map = map
  }

  iterate(n) { _map.iterate(n) }
  iteratorValue(iterator) { _map.valueIteratorValue_(iterator) }
}

class Range is Sequence {}

class System {
  static print() {
    writeString_("\n")
  }

  static print(obj) {
    writeObject_(obj)
    writeString_("\n")
    return obj
  }

  static printAll(sequence) {
    for (object in sequence) writeObject_(object)
    writeString_("\n")
  }

  static write(obj) {
    writeObject_(obj)
    return obj
  }

  static writeAll(sequence) {
    for (object in sequence) writeObject_(object)
  }

  static writeObject_(obj) {
    var string = obj.toString
    if (string is String) {
      writeString_(string)
    } else {
      writeString_("[invalid toString]")
    }
  }
}

class ClassAttributes {
  self { _attributes }
  methods { _methods }
  construct new(attributes, methods) {
    _attributes = attributes
    _methods = methods
  }
  toString { "attributes:%(_attributes) methods:%(_methods)" }
}
