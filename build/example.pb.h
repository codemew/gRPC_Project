// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: example.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_example_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_example_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_example_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_example_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_example_2eproto;
namespace calculator {
class AddRequest;
class AddRequestDefaultTypeInternal;
extern AddRequestDefaultTypeInternal _AddRequest_default_instance_;
class AddResponse;
class AddResponseDefaultTypeInternal;
extern AddResponseDefaultTypeInternal _AddResponse_default_instance_;
}  // namespace calculator
PROTOBUF_NAMESPACE_OPEN
template<> ::calculator::AddRequest* Arena::CreateMaybeMessage<::calculator::AddRequest>(Arena*);
template<> ::calculator::AddResponse* Arena::CreateMaybeMessage<::calculator::AddResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace calculator {

// ===================================================================

class AddRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:calculator.AddRequest) */ {
 public:
  AddRequest();
  virtual ~AddRequest();

  AddRequest(const AddRequest& from);
  AddRequest(AddRequest&& from) noexcept
    : AddRequest() {
    *this = ::std::move(from);
  }

  inline AddRequest& operator=(const AddRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline AddRequest& operator=(AddRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const AddRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AddRequest* internal_default_instance() {
    return reinterpret_cast<const AddRequest*>(
               &_AddRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(AddRequest& a, AddRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(AddRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline AddRequest* New() const final {
    return CreateMaybeMessage<AddRequest>(nullptr);
  }

  AddRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<AddRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const AddRequest& from);
  void MergeFrom(const AddRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AddRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "calculator.AddRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_example_2eproto);
    return ::descriptor_table_example_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kOperand1FieldNumber = 1,
    kOperand2FieldNumber = 2,
  };
  // int32 operand1 = 1;
  void clear_operand1();
  ::PROTOBUF_NAMESPACE_ID::int32 operand1() const;
  void set_operand1(::PROTOBUF_NAMESPACE_ID::int32 value);

  // int32 operand2 = 2;
  void clear_operand2();
  ::PROTOBUF_NAMESPACE_ID::int32 operand2() const;
  void set_operand2(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:calculator.AddRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::int32 operand1_;
  ::PROTOBUF_NAMESPACE_ID::int32 operand2_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_example_2eproto;
};
// -------------------------------------------------------------------

class AddResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:calculator.AddResponse) */ {
 public:
  AddResponse();
  virtual ~AddResponse();

  AddResponse(const AddResponse& from);
  AddResponse(AddResponse&& from) noexcept
    : AddResponse() {
    *this = ::std::move(from);
  }

  inline AddResponse& operator=(const AddResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline AddResponse& operator=(AddResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const AddResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AddResponse* internal_default_instance() {
    return reinterpret_cast<const AddResponse*>(
               &_AddResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(AddResponse& a, AddResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(AddResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline AddResponse* New() const final {
    return CreateMaybeMessage<AddResponse>(nullptr);
  }

  AddResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<AddResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const AddResponse& from);
  void MergeFrom(const AddResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AddResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "calculator.AddResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_example_2eproto);
    return ::descriptor_table_example_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSumFieldNumber = 1,
  };
  // int32 sum = 1;
  void clear_sum();
  ::PROTOBUF_NAMESPACE_ID::int32 sum() const;
  void set_sum(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:calculator.AddResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::int32 sum_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_example_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AddRequest

// int32 operand1 = 1;
inline void AddRequest::clear_operand1() {
  operand1_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 AddRequest::operand1() const {
  // @@protoc_insertion_point(field_get:calculator.AddRequest.operand1)
  return operand1_;
}
inline void AddRequest::set_operand1(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  operand1_ = value;
  // @@protoc_insertion_point(field_set:calculator.AddRequest.operand1)
}

// int32 operand2 = 2;
inline void AddRequest::clear_operand2() {
  operand2_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 AddRequest::operand2() const {
  // @@protoc_insertion_point(field_get:calculator.AddRequest.operand2)
  return operand2_;
}
inline void AddRequest::set_operand2(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  operand2_ = value;
  // @@protoc_insertion_point(field_set:calculator.AddRequest.operand2)
}

// -------------------------------------------------------------------

// AddResponse

// int32 sum = 1;
inline void AddResponse::clear_sum() {
  sum_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 AddResponse::sum() const {
  // @@protoc_insertion_point(field_get:calculator.AddResponse.sum)
  return sum_;
}
inline void AddResponse::set_sum(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  sum_ = value;
  // @@protoc_insertion_point(field_set:calculator.AddResponse.sum)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace calculator

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_example_2eproto
