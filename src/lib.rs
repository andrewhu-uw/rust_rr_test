use std::vec::Vec;
use std::boxed::Box;
use std::ffi;
use std::os::raw::c_char;

#[repr(C)]
#[no_mangle]
pub struct StringListContainer {
  mContainer : Vec<String>
}

impl StringListContainer {
  fn new() -> StringListContainer {
    StringListContainer { mContainer : Vec::new() } 
  }

  fn Add(&mut self, s : String) -> &mut StringListContainer {
    self.mContainer.push(s);
    self
  }

  fn Count(&self) -> usize {
    self.mContainer.len()
  }

  fn print(&self) {
    self.mContainer.iter().for_each(|x| println!("{}", x));
  }
}

/* FFI part */
#[no_mangle]
pub extern fn new_StringListContainer() -> *mut StringListContainer {
  let slc = StringListContainer::new();
  Box::into_raw(Box::new(slc))
}

#[no_mangle]
pub unsafe extern fn StringListContainer_Add(slc_p : *mut StringListContainer,
                                             s_p : *const c_char) {
    let c_str: &ffi::CStr = ffi::CStr::from_ptr(s_p);
    let str_slice: &str = c_str.to_str().unwrap();
    let string: String = str_slice.to_owned();  // if necessary
    
    let slc = &mut *slc_p;
    slc.Add(string);
}

#[no_mangle]
pub unsafe extern fn StringListContainer_print(slc_p : *const StringListContainer) {
  println!("Printing strings:");
  let slc = &*slc_p;
  slc.print();
  println!("Done!");
}

fn main() {
  let mut slc = StringListContainer::new();
  slc.Add("test".to_string());
  slc.Add("hello".to_string());
  slc.Add("world".to_string());
  slc.print();
  println!("{}", slc.Count());
}
