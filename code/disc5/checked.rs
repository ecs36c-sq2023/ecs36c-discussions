// from
// https://stanford-cs242.github.io/f19/lectures/07-1-traits.html#comparison-with-c-templates

fn print<T>(t: T) {
  t.print();
}

struct Foo;
impl Foo { fn print(&self) { println!("Foo"); } }

fn main() {
  print(Foo {});
}