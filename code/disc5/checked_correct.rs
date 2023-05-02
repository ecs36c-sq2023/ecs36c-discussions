
fn print<T: Printable>(t: T) {
  t.print();
}

trait Printable { fn print(&self); }

struct Foo;
impl Printable for Foo {
  fn print(&self) {
    println!("Foo"); 
  } 
}

struct Boo;

fn main() {
  print(Foo {});
}